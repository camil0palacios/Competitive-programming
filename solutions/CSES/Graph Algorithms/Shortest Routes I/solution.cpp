#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

typedef pair<int,int> ii;
typedef pair<ll, int> li;
const ll INF = 1e18;
const int MXN = 2e5 + 5;
vector<ii> g[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
    }
    priority_queue<li, vector<li>, greater<li>> q;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        int u = q.top().second;
        ll w = q.top().first;
        q.pop();
        if(w != dist[u]) continue;
        for(auto & e: g[u]) {
            int v = e.first;
            if(e.second + dist[u] < dist[v]) {
                dist[v] = dist[u] + e.second;
                q.push({dist[v], v});
            }
        }
    }
    for(auto & ans : dist) {
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}