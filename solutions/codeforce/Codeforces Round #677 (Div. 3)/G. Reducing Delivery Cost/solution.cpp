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

const int oo = 1e9 + 7;
const int Mxn = 1010;
int n, m, k;
vii g[Mxn];
ii edges[Mxn], routes[Mxn];
int d[Mxn][Mxn];

void dijkstra(int s) {
    fori(i,0,n) d[s][i] = oo;
    priority_queue<ii, vii, greater<ii>> q;
    q.push({0, s});
    d[s][s] = 0;
    while(!q.empty()) {
        int u = q.top().sd;
        int dis = q.top().ft;
        q.pop();
        if(dis > d[s][u]) continue;
        for(auto & e : g[u]) {
            int v = e.ft, w = e.sd;
            if(dis + w < d[s][v]) {
                d[s][v] = dis + w;
                q.emplace(d[s][v], v);
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    fori(i,0,m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].eb(v, w);
        g[v].eb(u, w);
        edges[i].ft = u, edges[i].sd = v;
    }
    fori(i,0,k) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        routes[i].ft = u, routes[i].sd = v;
    }
    fori(i,0,n) dijkstra(i);
    int ans = oo;
    fori(i,0,m) {
        int u = edges[i].ft, v = edges[i].sd;
        int tmp = 0;
        fori(j,0,k) {
            int a = routes[j].ft, b = routes[j].sd;
            tmp += min(d[a][b], min(d[a][u] + d[v][b], d[a][v] + d[u][b]));
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0; 
}