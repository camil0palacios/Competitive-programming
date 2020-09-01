struct Edge {
    int v, id, cap, cost;
    Edge(int v, int id, int cost, int cap): v(v), id(id), cost(cost), cap(cap) {} 
};

struct MCMF {

    int sz;
    vector<vector<Edge>> edges;

    MCMF(int n) : sz(n + 2) {
        edges.resize(sz + 1);
    } 

    void add_edge(int u, int v, int cost, int cap) {
        edges[u].emplace_back(v, edges[v].size(), cost, cap);
        edges[v].emplace_back(u, edges[u].size() - 1, -cost, 0);  
    }

    int flow(int n, int s, int t) {
        int f = 0, c = 0;
        while(true) {
            queue<int> q;
            vector<bool> inq(sz + 1, 0);
            vector<int> dis(sz + 1, INF);
            vector<int> p(sz + 1, -1), pidx(s + 1, - 1);
            dis[s] = 0;
            inq[s] = 1;
            q.push(s);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                inq[u] = 0;
                for(int i = 0; i < edges[u].size(); i++) {
                    int v = edges[u][i].v;
                    int cap = edges[u][i].cap;
                    if(cap && dis[u] + edges[u][i].cost < dis[v]) {
                        dis[v] = dis[u] + edges[u][i].cost;
                        p[v] = u;
                        pidx[v] = i;
                        if(!inq[v]) {
                            inq[v] = 1;
                            q.push(v);
                        }
                    }
                }
            } 
            if(p[t] == -1) break;
            int flow = INF;
            for(int i = t; i != s; i = p[i]) {
                int from = p[i];
                int idx = pidx[i];
                flow = min(flow, edges[from][idx].cap);
            }
            f += flow;
            for(int i = t; i != s; i = p[i]) {
                int from = p[i];
                int idx = pidx[i];
                edges[from][idx].cap -= flow;
                edges[i][edges[from][idx].id].cap += flow;
                c += flow * edges[from][idx].cost;
            }
        }
        return f == n ? c : -1;
    }    
};