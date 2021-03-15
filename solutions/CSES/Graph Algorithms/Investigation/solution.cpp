#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const ll oo = 1e18;
const ll mod = 1e9 + 7;
const int Mxn = 1e5 + 5;
int n, m;
bool vis[Mxn];
vii g[Mxn], r[Mxn]; 
ll dist[Mxn];
vi dag[Mxn];

void add(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod; 
}

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push({0, s});
    dist[s] = 0;
    while(!q.empty()) {
        int u = q.top().sd;
        ll dis = q.top().ft;
        q.pop();
        if(dis > dist[u]) continue;
        for(auto & e : g[u]) {
            int v = e.ft, w = e.sd;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v}); 
            }
        }
    }
}

ll dp1[Mxn], dp2[Mxn], dp3[Mxn];

bool isleaf(int u) { return sz(dag[u]) == 0; }

void dfs(int u) {
    vis[u] = 1;
    dp1[u] = 0, dp2[u] = oo, dp3[u] = -oo;
    if(isleaf(u) || u == n - 1) {
        if(u == n - 1) dp1[u] = 1, dp2[u] = dp3[u] = 0;  
        return;
    }
    for(auto & v: dag[u]) {
        if(!vis[v]) dfs(v);
        add(dp1[u], dp1[v]);
        dp2[u] = min(dp2[u], dp2[v] + 1);
        dp3[u] = max(dp3[u], dp3[v] + 1);
    }   
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fori(i,0,m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].eb(v, w);
        r[v].eb(u, w);
    }
    dijkstra(0);
    fori(i,0,n) {  // build a dag
        for(auto & e : g[i]) {
            int v = e.ft, w = e.sd;
            if(dist[i] + w == dist[v]) dag[i].eb(v);
        }
    }
    dfs(0);
    cout << dist[n-1] << ' ' << dp1[0] << ' ' << dp2[0] << ' ' << dp3[0] << endl;
    return 0;
}