#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll INF = 1e18;

struct Dinic {
    struct Edge {
        int u, v;
        ll flow = 0, cap;
        Edge(int u, int v, int cap): u(u), v(v), cap(cap) {}
    };
    int n, m = 0;
    int s, t;
    vector<Edge> edges; 
    vector<vector<int>> adj;
    vector<int> lvl, ptr;
    Dinic(int n, int s, int t): n(n), s(s), t(t) {
        adj.resize(n);
        lvl.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u, int v, ll cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].emplace_back(m);
        adj[v].emplace_back(m + 1);
        m += 2;
    }
    bool bfs(int s, int t) {
        queue<int> q;
        q.push(s);
        lvl[s] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto & id : adj[u]) {
                int v = edges[id].v;
                if(edges[id].cap - edges[id].flow < 1) continue;
                if(lvl[v] != -1) continue;
                lvl[v] = lvl[u] + 1;
                q.push(v);
            }
        }
        return lvl[t] != -1;
    }
    ll dfs(int u, ll pushed, int & t) {
        if(pushed == 0) return 0;
        if(u == t) return pushed;
        for(int & i = ptr[u]; i < adj[u].size(); i++) {
            int id = adj[u][i];
            int v = edges[id].v;
            if(lvl[u] + 1 != lvl[v] || edges[id].cap - edges[id].flow < 1) continue;
            ll ans = dfs(v, min(pushed, edges[id].cap - edges[id].flow), t);
            if(ans == 0) continue;
            edges[id].flow += ans;
            edges[id ^ 1].flow -= ans;
            return ans;
        }
        return 0;
    }
    ll flow() {
        ll f = 0;
        while(true) {
            fill(lvl.begin(), lvl.end(), -1);
            if(!bfs(s, t)) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll push = dfs(s, INF, t)) {
                f += push;
            }
        }
        return f;
    }
};

const int MXT = 1000;
vector<int> times[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int ti; cin >> ti;
        for(int j = 0; j < ti; j++) {
            int tt; cin >> tt;
            times[tt - 1].emplace_back(i);
        }
    }
    int s = n + MXT, t = n + MXT + 1;  
    Dinic g(n + MXT + 2, s, t);
    for(int i = 0; i < n; i++) g.add_edge(s, i, 1);
    for(int i = n; i < n + MXT; i++) g.add_edge(i, t, 1);
    int ans = 1e9;
    ll f = 0;
    for(int i = 0; i < MXT; i++) {
        ans = i;
        for(auto & v : times[i]) g.add_edge(v, n + i, 1);
        f += g.flow();
        if(f == n) break;
    }
    cout << ans + 2 << endl;
    return 0;
}