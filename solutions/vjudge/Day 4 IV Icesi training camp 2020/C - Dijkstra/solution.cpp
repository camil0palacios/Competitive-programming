#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
#define ll long long
using namespace std;

typedef pair<int,int> edge;

const ll INF = 1e18;
const int MXN = 1e5 + 5;
int n, m;
int p[MXN];
vector<edge> g[MXN];

ll dijkstra() {
    memset(p, -1, sizeof p);
    vector<ll> dist(n, INF);
    set<pair<ll,int>> q;
    q.insert({0, 0});
    dist[0] = 0;
    while(!q.empty()) {
        int u = q.begin()->sd;
        ll dis = q.begin()->ft;
        q.erase(q.begin());
        if(dis != dist[u]) continue;
        for(auto & e : g[u]) {
            int v = e.ft, w = e.sd;
            if(dist[u] + 1LL*w < dist[v]) {
                q.erase({dist[v], v});
                dist[v] = dist[u] + 1LL*w;
                p[v] = u;
                q.insert({dist[v], v}); 
            }
        }
    }
    return dist[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    if(dijkstra() == INF) cout << -1 << endl;
    else {
        vector<int> ans;
        for(int i = n - 1; i != -1; i = p[i]) {
            ans.emplace_back(i);
        }
        reverse(ans.begin(), ans.end());
        for(auto & u : ans) {
            cout << u + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}