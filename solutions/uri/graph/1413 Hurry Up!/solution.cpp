#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
using namespace std;

const int INF = 1e9;

struct MCMF {
    struct Edge {
        int to, cap, flow = 0;
        double cost;
        Edge(int to, int cap, double cost): to(to), cap(cap), cost(cost) {}
    };
    int sz;
    vector<Edge> edges;
    vector<vector<int>> adj;
    MCMF(int n): sz(n) {
        adj.resize(sz);
    }
    void add_edge(int u, int v, int cap, double cost) {
        edges.emplace_back(v, cap, cost);
        adj[u].emplace_back(edges.size() - 1);
        edges.emplace_back(u, 0, -cost);
        adj[v].emplace_back(edges.size() - 1);
    }
    int mcmf(int s, int t) {
        int f = 0;
        double c = 0;
        while(true) {
            vector<double> dist(sz, INF);
            set<pair<double,int>> q;
            vector<int> p(sz, -1);
            dist[s] = 0;
            q.insert({0, s});
            while(!q.empty()) {     // dijkstra
                int u = q.begin()->sd;
                int dis = q.begin()->ft;
                q.erase(q.begin());
                for(auto & id : adj[u]) {
                    int v = edges[id].to;
                    if(edges[id].cap - edges[id].flow > 0 && dist[u] + edges[id].cost < dist[v]) {
                        q.erase({dist[v], v});
                        dist[v] = dist[u] + edges[id].cost;
                        p[v] = id;
                        q.insert({dist[v], v});
                    }
                }
            }
            if(p[t] == -1) break;
            int flow = 0;
            for(int i = t; i != s; i = edges[p[i] ^ 1].to) {
                int id = p[i];
                flow = min(flow, edges[id].cap - edges[id].flow);
            }
            f += flow;
            c += f * dist[t];
            for(int i = t; i != s; i = edges[p[i] ^ 1].to) {
                int id = p[i];
                edges[id].flow -= flow;
                edges[id ^ 1].flow += flow;
            }
        }
        return c;
    }
};

const int MXN = 110;
double x[MXN], y[MXN], speed[MXN];

double dist(double x1, double y1, double x2, double y2) {
    double dx = 1.0*x1 - x2;
    double dy = 1.0*y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m && (n || m)) {
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> speed[i];
        }
        int s = n + m, t = n + m + 1;
        MCMF g(t + 1);
        for(int i = 0; i < m; i++) {
            double tx, ty; int c;
            cin >> tx >> ty;
            while(cin >> c && c) {
                c--;
                g.add_edge(c, n + i, 1, dist(x[c], y[c], tx, ty) * speed[c]);
            }
        }
        for(int i = 0; i < n; i++) {
            g.add_edge(s, i, 1, 0);
        }
        for(int i = 0; i < m; i++) {
            g.add_edge(n + i, t, 1, 0);
        }
        cout << g.mcmf(s, t) << endl;
    }
    return 0;
}