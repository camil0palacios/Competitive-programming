#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
vector<int> g[MXN];
int col[MXN];
vector<int> ans;
int cycle;
bool ok;

bool dfs(int u, int p) {
    col[u] = 1;
    for(auto & v : g[u]) {
        if(p == v) continue;
        if(!col[v] && dfs(v, u)) {
            if(ok) ans.emplace_back(u);
            if(u == cycle) ok = 0;
            return 1;
        }   
        else if(col[v] == 1) {
            ans.emplace_back(v);
            ans.emplace_back(u);
            cycle = v;
            ok = 1;
            return 1;
        }
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
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    bool poss = 0;
    for(int i = 0; i < n; i++) {
        if(!col[i] && dfs(i, i)) {
            poss = 1;
            break;
        }
    }
    if(poss) {
        cout << ans.size() << endl;
        for(auto & i : ans) {
            cout << i + 1 << ' ';
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}