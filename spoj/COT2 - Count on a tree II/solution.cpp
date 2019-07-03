#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int NMAX = 4e5 + 5;
const int ln = 18;
int n, m;
int val[NMAX], flat[NMAX << 1], depth[NMAX];
int tin[NMAX], tout[NMAX], cnt = 0;
int dp[NMAX][ln];

vector<int> g[NMAX];
map<long long, int> remap;

int bsize = sqrt(NMAX);

struct query{
    int l, r, lca, id;
    query(){}
    query(int _l, int _r, int _lca, int _id){
        l = _l, r = _r, lca = _lca, id = _id;
    }
    bool operator<(const query & q)const{
        return make_pair(l/bsize, r) < make_pair(q.l/bsize, q.r);
    }
};

void dfs(int u, int p){
    tin[u] = ++cnt;
    flat[cnt] = u;
    dp[u][0] = p;
    for(int i = 1; i < ln; i++){
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }
    for(auto & to : g[u]){
        if(to == p)continue;
        depth[to] = depth[u] + 1;
        dfs(to, u);
    }
    tout[u] = ++cnt;
    flat[cnt] = u;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
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

bool vis[NMAX];
int freq[NMAX];

void check(int u, int & res){
    if(vis[u] && (--freq[val[u]] == 0)){
        res--;
    }
    else if(!vis[u] && (freq[val[u]]++ == 0)){
        res++;
    }
    vis[u] ^= 1;
}

void mos_algorithm(vector<query> & Q){
    vector<int> ans(m);
    sort(Q.begin(), Q.end());
    int l = Q[0].l, r = Q[0].l - 1, res = 0;
    for(auto & q : Q){
        int lca = q.lca;
        while(l < q.l)check(flat[l++], res);
        while(l > q.l)check(flat[--l], res);
        while(r < q.r)check(flat[++r], res);
        while(r > q.r)check(flat[r--], res);
        int u = flat[l], v = flat[r];
        if(u != lca && v != lca)check(lca, res);
        ans[q.id] = res;
        if(u != lca && v != lca)check(lca, res); 
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        if(!remap.count(x))remap[x] = i;
        val[i] = remap[x];
    }
    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(0,0);
    vector<query> Q;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--, v--;
        int lca = get_lca(u,v);
        if(tin[u] > tin[v])swap(u,v);
        Q.push_back(query(u == lca ? tin[u] : tout[u], tin[v], lca, i));
    }
    mos_algorithm(Q);
    return 0;
}