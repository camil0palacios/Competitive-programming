#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
vector<int> g[MXN];
int col[MXN];
bool ok = 0;

void dfs(int u, int c) {
    col[u] = c;
    for(auto & v : g[u]) {
        if(col[v] == -1) {
            dfs(v, c ^ 1);
        }
        else if(col[v] == c) {
            ok = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    memset(col, -1, sizeof col);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i = 0; i < n; i++) {
        if(col[i] == -1) {
            dfs(i, 0);
        }
    }
    if(!ok) {
        for(int i = 0; i < n; i++) {
            cout << col[i] + 1 << ' '; 
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}