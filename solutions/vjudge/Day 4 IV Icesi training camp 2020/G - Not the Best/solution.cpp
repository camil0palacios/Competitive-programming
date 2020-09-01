#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 5010;
int n, m;

struct Edge {
    int v, w, op;
    Edge() {};
    Edge(int v, int w, int op): v(v), w(w), op(op) {}
    bool operator<(const Edge & e) const {
        if(op == e.op) return w > e.w;
        return op > e.op; 
    }
};

vector<Edge> g[MXN];
int dist[MXN][2];

void clear() { for(int i = 0; i < n; i++) g[i].clear(); }

int dijkstra() {
    for(int i = 0; i < n; i++) 
        dist[i][0] = dist[i][1] = INF;
    priority_queue<Edge> q;
    q.push(Edge(0, 0, 0));
    dist[0][0] = 0;
    while(!q.empty()) {
        int u = q.top().v;
        int dis = q.top().w;
        int op = q.top().op;
        q.pop();
        if(u == n - 1 && op == 1) return dist[n - 1][1];
        if(dis != dist[u][op]) continue;
        for(auto & e : g[u]) {
            int v = e.v, w = e.w;
            if(dis + w < dist[v][0]) {
                dist[v][1] = dist[v][0];
                dist[v][0] = dist[u][0] + w;
                q.push(Edge(v, dist[v][0], 0));
                q.push(Edge(v, dist[v][1], 1));
            }
            else if(dis + w > dist[v][0] && dis + w < dist[v][1]) {
                dist[v][1] = dis + w;
                q.push(Edge(v, dist[v][1], 1));
            }
        }
    }
    return INF;
}

int solve() {
    cin >> n >> m;
    clear();
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(Edge(v, w, 0));
        g[v].emplace_back(Edge(u, w, 0));
    }
    return dijkstra();
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": " << solve() << endl;
    }
    return 0;
}