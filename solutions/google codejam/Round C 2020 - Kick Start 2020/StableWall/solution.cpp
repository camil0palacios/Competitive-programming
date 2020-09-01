#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;

typedef unordered_set<int> us;

const int MXN = 35 + 5;
char a[MXN][MXN];
bool vis[26], mset[26], cycle;
int color[26];
us g[26], r[26];
vector<int> ord;

int dfs(int u) {
    color[u] = 1;
    for(auto & v : g[u]) { 
        if(color[v] == 0) {
            if(dfs(v)) return 1;
        } else if(color[v] == 1) {
            cycle = 1;
            return 1;
        }
    }
    color[u] = 2;
    return 0;
}

int dfs2(int u) {
    vis[u] = 1;
    for(auto & v : r[u]) {
        if(!vis[v]) {
            dfs2(v);
        }
    }
    ord.emplace_back(u);
}

void sol() {
    int n, m;
    cin >> n >> m;
    memset(mset, 0, sizeof mset);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            mset[a[i][j] - 'A'] = 1;
        }
    }
    for(int i = 0; i < 26; i++) {
        g[i].clear();
        r[i].clear();
    }
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n - 1; i++) {
            int u = a[i][j] - 'A', v = a[i + 1][j] - 'A';
            if(u == v) continue;
            g[u].insert(v);
            r[v].insert(u);
        }
    }
    cycle = 0;
    memset(color, 0, sizeof color);
    for(int i = 0; i < 26; i++) {
        if(mset[i] && !color[i]) dfs(i);
    }
    if(cycle) {
        cout << -1 << endl;
    } else {
        memset(vis, 0, sizeof vis);
        ord.clear();
        for(int i = 0; i < 26; i++) {
            if(mset[i] && !vis[i]) {
                dfs2(i);
            }
        }
        reverse(all(ord));
        for(int i = 0; i < ord.size(); i++) {
            cout << char(ord[i] + 'A');
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    } 
    return 0;
}