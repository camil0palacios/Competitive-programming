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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int oo = 1e9;
const int Mxn = 1e5 + 5;
int n, m;
vii g[Mxn];
ll dis[Mxn];

void dijkstra(int s, ll c) {
    fori(i,0,n) dis[i] = 0;
    priority_queue<ii> q;
    dis[s] = c;
    q.push(mp(c, s));
    while(!q.empty()) {
        int u = q.top().sd;
        int d = q.top().ft;
        q.pop();
        if(d < dis[u]) continue;
        for(auto & e : g[u]) {
            int v = e.ft;
            int w = e.sd;
            ll x = ceil(1.0*d*w/100);
            if(d - x > dis[v]) {
                dis[v] = d - x;
                q.push(mp(dis[v], v));
            }
        }
    }     
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int s, t, c;
    cin >> n >> m;
    cin >> s >> t >> c;
    s--, t--;
    fori(i,0,m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    dijkstra(s, c);
    cout << dis[t] << endl;
    return 0; 
}