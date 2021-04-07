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

const ll oo = 1e12;
const int Mxn = 1010;
int n, m, g, p;
int v[Mxn];
vii G[Mxn];
ll dist[Mxn][Mxn];
ll dp[Mxn][Mxn];

void dijsktra(int s) {
    fori(i,0,n) dist[s][i] = oo;
    priority_queue<ii, vii, greater<ii>> q;
    dist[s][s] = 0;
    q.emplace(0, s);
    while(!q.empty()) {
        int u = q.top().sd;
        int d = q.top().ft;
        q.pop();
        if(d > dist[s][u]) continue;
        for(auto & e : G[u]) {
            int v = e.ft, w = e.sd;
            if(dist[s][u] + w < dist[s][v]) {
                dist[s][v] = dist[s][u] + w;
                q.emplace(dist[s][v], v);
            }
        }
    }
}

ll go(int i, int u) {
    if(i == p) return 0;
    if(dp[i][u] != -1) return dp[i][u];
    ll ans = oo;
    ans = min(ans, go(i + 1, u) + dist[v[i]][0]);
    if(dist[0][u] + dist[v[i]][u] == dist[0][v[i]])
        ans = min(ans, go(i + 1, u) + dist[v[i]][u] + g);
    return dp[i][u] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> p >> g;
    fori(i,0,p) cin >> v[i], v[i]--; 
    fori(i,0,m) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].eb(v, c);
        G[v].eb(u, c);
    }
    dijsktra(0);
    fori(i,0,p) dijsktra(v[i]);
    memset(dp, -1, sizeof dp);
    ll ans = oo;
    fori(i,0,n) ans = min(ans, go(0, i));
    cout << ans << endl;
    return 0; 
}