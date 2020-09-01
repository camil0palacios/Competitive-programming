#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
#define ll long long
using namespace std;

typedef pair<int,int> edge;
typedef unordered_map<int, int> um;

const ll INF = 1e18;
const int MXN = 1e5 + 5;
int n, m;
vector<int> k[MXN];
vector<edge> g[MXN];
um jumps[MXN];

ll dijkstra() {
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
            if(dist[u] + 1LL*w + 1LL*jumps[u][dist[u]] < dist[v]) {
                q.erase({dist[v], v});
                dist[v] = dist[u] + w + jumps[u][dist[u]];
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
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int j = 0; j < x; j++) {
            int t; cin >> t;
            k[i].emplace_back(t);
        }
    }
    for(int i = 0; i < n; i++) {
        if(k[i].size()) {
            int lst = k[i].back();
            jumps[i][lst] = 1;
            for(int j = k[i].size() - 2; j >= 0; j--) {
                if(k[i][j] == k[i][j + 1] || (k[i][j] + 1 == k[i][j + 1])) {
                    jumps[i][k[i][j]] = (lst + 1) - k[i][j];
                } else {
                    lst = k[i][j];
                    jumps[i][lst] = 1;
                }
            } 
        }
    }
    ll ans = dijkstra();
    cout << (ans != INF ? ans : -1) << endl;
    return 0;
}