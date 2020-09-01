#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int NMAX = 1e6 + 5;
vector<int> g[NMAX];
int tin[NMAX], depth[NMAX], up[NMAX][20], tout[NMAX];
bool vis[NMAX];
int timer = 0;

void dfs(int u){
    tin[u] = timer++;
    vis[u] = 1;
    for(auto & to : g[u]){
        if(!vis[to]){
            depth[to] = depth[u] + 1;
            up[to][0] = u;
            for(int i = 1; i < 20; i++){
                up[to][i] = up[up[to][i-1]][i-1];
            }
            dfs(to);
        }
    }
    tout[u] = timer++;
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a]; 
}

int get_lca(int a, int b){
    if(is_ancestor(a,b))return a;
    if(is_ancestor(b,a))return b;
    for(int i = 19; i >= 0; --i){
        if(!is_ancestor(up[a][i],b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}

/*
int lca(int a, int b){ // other way to obtain lca
    if(depth[a] < depth[b])swap(a,b);
    for(int i = 19; i >= 0; i--){
        if(depth[a] >= depth[b] + (1 << i)){
            a = up[a][i];
        }
    }
    assert(depth[a] == depth[b]);
    for(int i = 19; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    if(a != b){
        a = up[a][0];
        b = up[b][0];
    }
    assert(a == b);
    return a;
}*/

void add_edge(int a, int b){
    g[a].emplace_back(b);
    g[b].emplace_back(a);
}

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, u;
    cin >> n >> m;
    vector<vector<int>> query(m);
    for(int i = 0; i < n; i++){
        cin >> u;
        query[u-1].emplace_back(i);
    }
    for(int i = 0; i < n; i++){
        cin >> u;
        u--;
        if(u != -1){
            add_edge(i,u);
        }
    }
    dfs(0);
    for(auto & q : query){
        sort(q.begin(), q.end(), [&](int a, int b){
            return tin[a] < tin[b];
        });
        int ans = depth[q[0]] + 1;
        for(int i = 1; i < (int)q.size(); i++){
            int a = q[i-1];
            int b = q[i];
            //int x = lca(a,b);
            int x = get_lca(a,b);
            ans += depth[b] - depth[x]; 
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}