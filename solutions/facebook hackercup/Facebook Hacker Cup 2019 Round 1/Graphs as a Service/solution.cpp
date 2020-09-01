#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
#define mp make_pair
using namespace std;

const int INF = 1e9;
const int MXN = 55;
int n, m;
int g[MXN][MXN];

void floyd() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            g[i][j] = INF;
    }
    vector<pair<pair<int,int>,int>> q;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u][v] = g[v][u] = w;
        q.emplace_back(mp(u, v), w);
    }
    floyd();
    bool ok = 1;
    for(int i = 0; i < m; i++) {
        int u = q[i].ft.ft, v = q[i].ft.sd, w = q[i].sd;
        ok &= g[u][v] == w;
    }
    if(ok) {
        cout << m << endl;
        for(int i = 0; i < m; i++) {
            cout << q[i].ft.ft + 1 << ' ' << q[i].ft.sd + 1 << ' ' << q[i].sd << endl;
        }
    } else {
        cout << "Impossible" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}