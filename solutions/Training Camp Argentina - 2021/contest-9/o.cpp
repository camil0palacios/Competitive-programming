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

const int Mxn = 1e5 + 5;
int r[Mxn];
vii g[Mxn]; 
vi to[Mxn];
map<int, int> ids;
ii edges[Mxn];
bool vis[Mxn];

void dfs(int u, int id = -1) {
    vis[u] = 1;
    if(id != -1 && !ids[id]) {
        for(auto & e : g[u]) {
            int nid = e.sd;
            ids[nid] ^= 1;
        }
    }
    for(auto & e : g[u]) {
        int v = e.ft, nid = e.sd;
        if(nid == id || vis[v]) continue;
        dfs(v, nid);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) cin >> r[i];
    fori(i,0,m) {
        int x; cin >> x;
        fori(j,0,x) {
            int y; cin >> y; y--;
            to[y].eb(i);
        }
    }
    fori(i,0,n) {
        int u = to[i][0], v = to[i][1];
        g[u].eb(v, i);
        g[v].eb(u, i);
        ids[i] = r[i];
    }
    fori(i,0,m) if(!vis[i]) dfs(i);
    bool ok = 1;
    fori(i,0,n) ok &= ids[i];
    cout << (ok ? "YES" : "NO") << endl;
    return 0; 
}