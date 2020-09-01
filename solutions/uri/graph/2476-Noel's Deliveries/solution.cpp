#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int NMAX = 1e5 + 5;
const int ln = 20; 
int N, M, cur;
vector<int> g[NMAX];
int dp[NMAX][ln];
int tin[NMAX], tout[NMAX], depth[NMAX];
int flat[NMAX << 1];
int bsize = sqrt(NMAX);

map<string,int> m;

struct query{
    int id, l, r, lca;
    query(){}
    bool operator<(const query & q)const{
        return make_pair(l/bsize, r) < make_pair(q.l/bsize, q.r);
    }
};

void dfs(int u, int p){
    tin[u] = ++cur;
    flat[cur] = u;
    dp[u][0] = p;
    for(int i = 1; i < ln; i++){
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }
    for(auto & to : g[u]){
        if(to != p){
            depth[to] = depth[u] + 1;
            dfs(to,u);
        }
    }
    tout[u] = ++cur; 
    flat[cur] = u;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_lca(int u, int v){
    if(depth[u] < depth[v])swap(u,v);
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    for(int i = ln-1; i >= 0; i--){
        if(!is_ancestor(dp[u][i],v)){
            u = dp[u][i];
        }
    }
    return dp[u][0];
}

int frq[NMAX], val[NMAX];
bool vis[NMAX];

void check(int u, int & ans){
    if(vis[u] && (--frq[val[u]] == 0)){
        ans--;
    }
    else if(!vis[u] && (frq[val[u]]++ == 0)){
        ans++;
    }
    vis[u] ^= 1;
}

void mos_algorithm(vector<query> & Q){
    vector<int> ans(M);
    sort(Q.begin(), Q.end());
    int l = Q[0].l, r = Q[0].l - 1;
    int res = 0;
    for(auto & q : Q){
        int lca = q.lca;
        while(l < q.l){
            check(flat[l++], res);
        }
        while(l > q.l){
            check(flat[--l], res);
        }
        while(r < q.r){
            check(flat[++r], res);
        }
        while(r > q.r){
            check(flat[r--], res);
        }
        int u = flat[l], v = flat[r];
        if(u != lca && v != lca){
            check(lca, res);
        }
        ans[q.id] = res;
        if(u != lca && v != lca){
            check(lca, res);
        }
    }
    for(int i = 0; i < M; i++){
        cout << ans[i] << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int u, v;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        if(!m.count(s))m[s] = i;
        val[i] = m[s];
    }
    for(int i = 0; i < N-1; i++){
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    cur = 0;
    dfs(0,0);
    vector<query> Q(M);
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        u--, v--;
        Q[i].lca = get_lca(u,v);
        if(tin[u] > tin[v])swap(u,v);
        if(Q[i].lca != u){
            Q[i].l = tout[u], Q[i].r = tin[v];
        }else{
            Q[i].l = tin[u], Q[i].r = tin[v];
        }
        Q[i].id = i;
    }
    mos_algorithm(Q);
    return 0;
}