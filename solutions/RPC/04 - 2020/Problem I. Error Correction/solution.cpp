#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int INF = 1e9;
const int MXN = 501;
string a[MXN];

struct Edge {
    int u, v;
    ll flow = 0, cap;
    Edge(int u, int v, int cap): u(u), v(v), cap(cap) {}
};

struct Dinic {
    const ll inf = 1e18;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> lvl, ptr;
    int n, m = 0;
    int s, t;
    
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
    
    bool bfs() {
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int id : adj[u]) {
                if(edges[id].cap - edges[id].flow < 1) continue;
                if(lvl[edges[id].v] != -1) continue;
                lvl[edges[id].v] = lvl[u] + 1;
                q.push(edges[id].v);
            }
        }
        return lvl[t] != -1;
    }
    
    int dfs(int u, ll pushed) {
        if(pushed == 0) return 0;
        if(u == t) return pushed;
        for(int & cid = ptr[u]; cid < adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if(lvl[u] + 1 != lvl[v] || edges[id].cap - edges[id].flow < 1) continue;
            ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if(tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while(true) {
            fill(lvl.begin(), lvl.end(), -1);
            lvl[s] = 0;
            if(!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(s, inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

bool match(string & s, string & t) {
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        cnt += s[i] != t[i];
    }
    return cnt == 2;
}

vector<int> g[MXN];
bool vis[MXN], col[MXN];

void dfs(int u, int c) {
    col[u] = c;
    vis[u] = 1;
    for(auto & v : g[u]) {
        if(!vis[v]) dfs(v, c ^ 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(match(a[i], a[j])) {
                g[i].emplace_back(j);
                g[j].emplace_back(i);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, 0);
    }
    int s = n, t = n + 1, sz = n + 2;
    Dinic gf(sz, s, t);
    for(int i = 0; i < n; i++) {
        if(col[i] == 0) {
            gf.add_edge(s, i, 1);
            for(int & v : g[i]) 
                gf.add_edge(i, v, INF);
        }
        else gf.add_edge(i, t, 1);
    }
    int ans = gf.flow();
    cout << n - ans << endl;
    return 0;
}