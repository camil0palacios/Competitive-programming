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