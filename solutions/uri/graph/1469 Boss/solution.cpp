#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 505;
int n, m, q;
int ages[MXN];
int emp_node[MXN], node_emp[MXN];
bool vis[MXN];
vector<int> g[MXN];

int dfs(int u) {
    vis[u] = 1;
    int ans = ages[node_emp[u]];
    for(auto & v: g[u]) {
        if(!vis[v]) ans = min(ans, dfs(v));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> m >> q) {
        for(int i = 0; i < n; i++) {
            cin >> ages[i];
            g[i].clear();
            emp_node[i] = node_emp[i] = i; 
        }
        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            g[v].emplace_back(u);
        }
        for(int qq = 0; qq < q; qq++) {
            char t; int u;
            cin >> t >> u;
            u--;
            if(t == 'P') {
                int mn = INF;
                for(int i = 0; i < n; i++) vis[i] = 0;
                for(auto & v : g[emp_node[u]]) {
                    mn = min(mn, dfs(v));      
                }
                if(mn < INF) cout << mn << endl;
                else cout << "*" << endl;
            } else {
                int v; cin >> v;
                v--;
                int nu = emp_node[u], nv = emp_node[v];
                swap(emp_node[u], emp_node[v]);
                swap(node_emp[nu], node_emp[nv]);
            }
        }
    }
    return 0;
}