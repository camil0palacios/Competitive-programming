#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
#define ll long long
using namespace std;

const ll INF = 1e18;
const int MXN = 500;
int n, m;
map<string, int> mpp, mt;
ll cost[MXN];
ll dist[MXN][5];

struct Edge {
    int v, tr;
    ll w;
    Edge(int v, ll w, int tr): v(v), w(w), tr(tr) {} 
};

vector<Edge> g[MXN];

ll dijkstra(int s, int t) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            dist[i][j] = INF;
        }
    }
    priority_queue<pair<ll, pair<int,int>>, vector<pair<ll, pair<int,int>>>, 
        greater<pair<ll, pair<int,int>>>> q;
    for(int i = 0; i < 5; i++) {
        dist[s][i] = 0;
        q.push(mp(0, mp(s, i)));
    }
    while(!q.empty()) {
        int u = q.top().second.first;
        int x = q.top().second.second;
        int dis = q.top().first;
        q.pop();
        if(dis > dist[u][x]) continue;
        for(auto & e: g[u]) {
            int v = e.v;
            int nxt = e.tr;
            ll ncost = (x != nxt ? cost[u] : 0);
            if(dist[u][x] + e.w + ncost < dist[v][nxt]) {
                dist[v][nxt] = dist[u][x] + e.w + ncost;
                q.push(mp(dist[v][nxt], mp(v, nxt)));
            }
        }
    }
    ll mn = INF;
    for(int i = 0; i < 5; i++) {
        mn = min(mn, dist[t][i]);
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    mt["AIR"] = 0, mt["BOAT"] = 1, mt["RAIL"] = 2, mt["TRUCK"] = 3, mt["SEA"] = 4;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s >> cost[i];
            mpp[s] = i;
            g[i].clear();
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            string u, v, tr;
            ll c;
            cin >> u >> v >> tr >> c;
            g[mpp[u]].emplace_back(mpp[v], c, mt[tr]);
            g[mpp[v]].emplace_back(mpp[u], c, mt[tr]);
        }
        string o, d;
        cin >> o >> d;
        cout << dijkstra(mpp[o], mpp[d]) << endl;
    }
    return 0;
}