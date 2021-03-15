#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

typedef pair<int,int> ii;
const ll INF = 1e18;
const int MXN = 1e5 + 5;
vector<ii> g[MXN];

struct node { 
    int u; ll w; bool cup;
    node(){}
    node(int u, ll w, bool cup): u(u), w(w), cup(cup) {}
    bool operator<(const node & n) const {
        if(w == n.w) return cup > n.cup;
        return w > n.w;
    }    
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c; 
        u--, v--;
        g[u].emplace_back(c, v);
    }
    priority_queue<node>  q;
    vector<vector<ll>> dist(n, vector<ll>(2, INF));
    dist[0][0] = dist[0][1] = 0;
    q.emplace(0, 0, 0);
    while(!q.empty()) {
        int u = q.top().u;
        ll w = q.top().w;
        bool cup = q.top().cup;
        q.pop();
        if(w != dist[u][cup]) continue;
        for(auto & e : g[u]) {
            int v = e.second;
            int d = e.first;
            if(!cup) {
                if(dist[u][0] + d < dist[v][0]) {
                    dist[v][0] = dist[u][0] + d;
                    q.emplace(v, dist[v][0], 0);
                }
                if(dist[u][0] + d/2 < dist[v][1]) {
                    dist[v][1] = dist[u][0] + d/2;
                    q.emplace(v, dist[v][1], 1);
                }
            } else {
                if(dist[u][1] + d < dist[v][1]) {
                    dist[v][1] = dist[u][1] + d;
                    q.emplace(v, dist[v][1], 1);
                }
            }
        }
    }
    cout << min(dist[n - 1][0], dist[n - 1][1]) << endl;
    return 0;
}