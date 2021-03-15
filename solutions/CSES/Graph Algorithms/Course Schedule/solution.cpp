#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
vector<int> g[MXN];
bool vis[MXN];
int col[MXN];
vector<int> top;

void dfs(int u) {
    vis[u] = 1; 
    for(auto & v : g[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    top.emplace_back(u);
}

bool dfs2(int u) {
    col[u] = 1;
    for(auto & v: g[u]) {
        if(!col[v] && dfs2(v)) return 1;
        else if(col[v] == 1) return 1;
    }
    col[u] = 2;
    return 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; u--, v--;
        g[u].emplace_back(v);
    }
    bool cycle = 0;
    for(int i = 0; i < n; i++) {
        if(!col[i] && dfs2(i)) {
            cycle = 1;
            break;
        }
    }
    if(!cycle) {
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i);
        }
        reverse(top.begin(), top.end());
        for(auto & u : top) {
            cout << u + 1 << ' ';
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0; 
}