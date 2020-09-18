#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
using namespace std;

const double INF = 1e9;

struct MCMF {
    struct Edge {
        int to, cap, flow = 0;
        double cost;
        Edge(int to, int cap, double cost): to(to), cap(cap), cost(cost) {}
    };
    int n, m;
    vector<Edge> edges;
    vector<vector<int>> adj;
    MCMF(int n): n(n) {
        adj.resize(n);
        m = 0;
    }
    void add_edge(int u, int v, int cap, double cost) {
        edges.emplace_back(v, cap, cost);
        edges.emplace_back(u, 0, -cost);
        adj[u].emplace_back(m);
        adj[v].emplace_back(m + 1);
        m += 2;
    }
    double mcmf(int s, int t) {
        int flow = 0;
        double cost = 0;
        while(true) {
            vector<double> dist(n, INF);
            set<pair<double, int>> q;
            vector<int> p(n, -1);
            dist[s] = 0;
            q.insert({0, s});
            while(!q.empty()) {     // dijkstra
                int u = q.begin()->sd;
                int dis = q.begin()->ft;
                q.erase(q.begin());
                for(auto & id : adj[u]) {
                    int v = edges[id].to;
                    if(edges[id].cap - edges[id].flow < 1) continue;
                    if(dist[u] + edges[id].cost < dist[v]) {
                        q.erase({dist[v], v});
                        dist[v] = dist[u] + edges[id].cost;
                        p[v] = id;
                        q.insert({dist[v], v});
                    }
                }
            }
            if(p[t] == -1) break;
            int f = (int) INF;
            for(int i = t; i != s; i = edges[p[i] ^ 1].to) {
                int id = p[i];
                f = min(f, edges[id].cap - edges[id].flow);
            }
            flow += f;
            cost += f * dist[t];
            for(int i = t; i != s; i = edges[p[i] ^ 1].to) {
                int id = p[i];
                edges[id].flow += f;
                edges[id ^ 1].flow -= f;
            }
        }
        return cost;
    }
};

const int MXN = 110;
double x[MXN], y[MXN], speed[MXN];

double dist(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(1);
    int n, m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> speed[i];
        }
        int s = n + m, t = n + m + 1;
        MCMF mcmf(t + 1);
        for(int i = 0; i < m; i++) {
            double tx, ty; int c;
            cin >> tx >> ty;
            while(cin >> c && c) {
                c--;
                mcmf.add_edge(c, n + i, 1, dist(x[c], y[c], tx, ty) / speed[c]);
            }
        }
        for(int i = 0; i < n; i++) {
            mcmf.add_edge(s, i, 1, 0);
        }
        for(int i = 0; i < m; i++) {
            mcmf.add_edge(n + i, t, 1, 0);
        }
        cout << mcmf.mcmf(s, t) << endl;
    }
    return 0;
}