#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
vector<int> g[MXN];
int leaf;
int par[MXN], sz[MXN];

void dfs(int u, int p = 0) {
    par[u] = p;
    sz[u] = 1;
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
} 

void dfs2(int u, int p = 0) {
    int ch = 0;
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs2(v, u);
        ch++;
    }
    if(!ch) leaf = u;
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1);
        int u = 0;
        for(int i = 1; i <= n; i++) {
            if(sz[i] == n / 2) { 
                u = i; break; 
            }
        }
        if(!u || (n & 1)) {
            cout << 1 << ' ' << g[1][0] << endl;
            cout << 1 << ' ' << g[1][0] << endl;            
        } else {
            dfs2(u, par[u]);
            cout << leaf << ' ' << par[leaf] << endl;
            cout << leaf << ' ' << par[u] << endl;
        } 
    }
    return 0;
}