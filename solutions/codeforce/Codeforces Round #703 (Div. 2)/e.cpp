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
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll oo = 1ll << 50;
const int Mxn = 1e5 + 5;
ll dist[Mxn];
vii g[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    fori(i,0,n) dist[i] = oo;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    dist[0] = 0;
    q.emplace(0, 0);
    while(!q.empty()) {
        int a = q.top().sd;
        int d = q.top().ft;
        q.pop();
        if(d > dist[a]) continue;
        for(auto & e1 : g[a]) {
            int b = e1.ft, wab = e1.sd;
            for(auto & e2 : g[b]) {
                int c = e2.ft, wbc = e2.sd;
                if(a == c) continue;
                ll x = wab + wbc;
                if(dist[a] + x*x < dist[c]) {
                    dist[c] = dist[a] + x*x;
                    q.emplace(dist[c], c);
                }
            }
        }
    }
    fori(i,0,n) cout << (dist[i] != oo ? dist[i] : -1) << ' ';
    cout << endl;
    return 0; 
}