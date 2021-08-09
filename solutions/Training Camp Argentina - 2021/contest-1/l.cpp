#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll oo = 1e14;

struct MCMF {
    struct Edge {
        int to;
        ll cap, flow = 0, cost;
        Edge(int to, ll cap, ll cost): to(to), cap(cap), cost(cost) {}
    };
    int n, m;
    vector<Edge> edges;
    vector<vector<int>> adj;
    MCMF(int n): n(n) {
        adj.resize(n);
        m = 0;
    }
    void add_edge(int u, int v, ll cap, ll cost) {
        edges.emplace_back(v, cap, cost);
        edges.emplace_back(u, 0, -cost);
        adj[u].emplace_back(m);
        adj[v].emplace_back(m + 1);
        m += 2;
    }
    ll mcmf(int s, int t) {
        ll flow = 0, cost = 0;
        while(true) {
            vector<ll> dist(n, oo);
            set<pair<ll, int>> q;
            vector<int> p(n, -1);
            dist[s] = 0;
            q.insert({0, s});
            while(!q.empty()) {     // dijkstra
                int u = q.begin()->sd;
                ll dis = q.begin()->ft;
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
            ll f = oo;
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

const int Mxn = 2205;
int a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];
    fori(i,0,n) cin >> b[i];
    int s = 2*n, t = s+1;
    MCMF g(t+2);
    fori(i,1,n) {
        g.add_edge(i-1, i, oo, 0);
        g.add_edge(n+i-1, n+i, oo, 0);
    }
    fori(i,0,n) {
        g.add_edge(i, i+n, 1, a[i]);
        g.add_edge(i+n, t, 1, b[i]);
    }
    g.add_edge(s, 0, k, 0);
    cout << g.mcmf(s, t) << endl;
    return 0; 
}