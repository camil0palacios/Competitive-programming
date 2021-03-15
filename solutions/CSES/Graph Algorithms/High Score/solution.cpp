#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

struct edge { int u, v, w; };
const int MXN = 2505;
const ll INF = 1e18;
typedef pair<int,int> ii;
ll dist[MXN];
bool vis1[MXN], vis2[MXN];
vector<ii> g[MXN];
vector<int> g2[MXN];

void dfs(int u) {
    vis1[u] = 1;
    for(auto & e : g[u]) {
        if(!vis1[e.second]) dfs(e.second);
    }
}

void dfs2(int u) {
    vis2[u] = 1;
    for(auto & v: g2[u]) {
        if(!vis2[v]) dfs2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; u--, v--;
        g[u].emplace_back(w, v);
        g2[v].emplace_back(u);
    }
    dfs(0);
    dfs2(n - 1);
    memset(dist, 0xc0, sizeof dist);
    dist[0] = 0;
    for(int i = 0; i < 2*n; i++) {
        bool ok = 0;
        for(int j = 0; j < n; j++) {
            for(auto & e : g[j]) {
                int v = e.second, w = e.first;
                if(dist[j] + w > dist[v]) {
                    if(vis1[v] && vis2[v]) ok = 1;
                    dist[v] = dist[j] + w;
                }
            }
        }
        if(i >= n - 1 && ok) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << dist[n - 1] << endl;
    return 0;
}