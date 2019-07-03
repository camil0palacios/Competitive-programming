#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define ll long long
using namespace std;

const int nmax = 1e5 + 5;
const int bsize = 320;
const int ln = 20;
int n, m;

ll c[nmax], h[nmax];
int flat[nmax << 1], tin[nmax], tout[nmax];
int depth[nmax], dp[nmax][ln], cur = 0;
bool vis[nmax];

vector<int> g[nmax];

struct query{
    int l, r, lca, id;
    query(){}
    query(int _l, int _r, int _lca, int _id){
        l = _l, r = _r, lca = _lca, id = _id;
    }
    bool operator<(const query & q)const{
        return mp(l/bsize, r) < mp(q.l/bsize, q.r);
    }
};

void dfs(int u, int p){
    tin[u] = ++cur;
    flat[cur] = u;
    dp[u][0] = p;
    for(int i = 1; i < ln; i++){
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }
    for(auto & v : g[u]){
        if(v == p)continue;
        depth[v] = depth[u] + 1;
        dfs(v,u);
    }
    tout[u] = ++cur;
    flat[cur] = u;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int get_lca(int u, int v){
    if(depth[u] < depth[v])swap(u,v);
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    for(int i = ln-1; i >= 0; i--){
        if(!is_ancestor(dp[u][i], v)){
            u = dp[u][i];
        }
    }
    return dp[u][0];
}

deque<int> q[11];
ll val[nmax];

void check_left(int u, ll & res){
    int col = c[u];
    res -= val[col];
    if(vis[u]){
        int x = q[col].front();
        q[col].pop_front();
        if(!q[col].empty()){
            int y = q[col].front();
            val[col] -= (h[x] - h[y])*(h[x] - h[y]);
        }

    }else{
        if(!q[col].empty()){
            int v = q[col].front();
            val[col] += (h[u] - h[v])*(h[u] - h[v]);
        }
        q[col].push_front(u);
    }
    res += val[col];
    vis[u] ^= 1;
}

void check_right(int u, ll & res){
    int col = c[u];
    res -= val[col];
    if(vis[u]){
        int x = q[col].back();
        q[col].pop_back();
        if(!q[col].empty()){
            int y = q[col].back();
            val[col] -= (h[x] - h[y])*(h[x] - h[y]);
        }
    }else{
        if(!q[col].empty()){ 
            int v = q[col].back();
            val[col] += (h[u] - h[v])*(h[u] - h[v]);
        }
        q[col].push_back(u);
    }
    res += val[col];
    vis[u] ^= 1;
}

void mos_algorithm(vector<query> & Q){
    vector<ll> ans(m);
    sort(Q.begin(), Q.end());
    int l = Q[0].l, r = Q[0].l-1;
    ll res = 0;
    for(auto & q : Q){
        while(l < q.l)check_left(flat[l++],res);
        while(l > q.l)check_left(flat[--l],res);
        while(r < q.r)check_right(flat[++r],res);
        while(r > q.r)check_right(flat[r--],res);
        ans[q.id] = res - val[c[q.lca]];
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    int u, v;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1,1);
    vector<query> Q;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        int lca = get_lca(u,v);
        if(tin[u] > tin[v])swap(u,v);
        Q.eb(u == lca ? tin[u] : tout[u], tin[v], lca, i);
    }
    mos_algorithm(Q);
    return 0;
}