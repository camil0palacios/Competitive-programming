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

const ll INF = 1e14;

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

int c[6];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<string, int> m({{"S", 0}, {"M", 1}, {"L", 2}, {"XL", 3}, {"XXL", 4}, {"XXXL", 5}});
    string rm[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
    fori(i,0,6) cin >> c[i];
    int n;
    cin >> n;
    int s = n + 6, t = s + 1;
    Dinic g(t+4, s, t);
    fori(i,0,n) {
        string x, tmp;
        cin >> x;
        fori(j,0,sz(x)) {
            if(x[j] == ',') {
                g.add_edge(i, m[tmp]+n, 1);
                tmp = "";
            } else tmp += x[j];
        }
        g.add_edge(i, m[tmp]+n, 1);
        g.add_edge(s, i, 1);
    }
    fori(i,0,6) g.add_edge(n+i, t, c[i]);
    if(g.flow() == n) {
        cout << "YES" << endl;
        fori(i,0,n) {
            for(auto id : g.adj[i]) {
                ll flow = g.edges[id].flow;
                ll cap = g.edges[id].cap;
                int v = g.edges[id].v;
                if(flow && flow == cap && v-n >= 0 && v-n < 6) {
                    cout << rm[v-n] << endl;
                    break;
                }
            }
        }
    } else cout << "NO" << endl;
    return 0; 
}