#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll INF = 1e18;
const int MXN = 505;
ll dist[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; u--, v--;
        dist[u][v] = dist[v][u] = min(dist[u][v], 1LL*w);
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v; u--, v--;
        if(dist[u][v] < INF) cout << dist[u][v] << endl;
        else cout << -1 << endl;
    }
    return 0;
}