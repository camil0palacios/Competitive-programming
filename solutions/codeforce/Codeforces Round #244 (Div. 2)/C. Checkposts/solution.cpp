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

const ll mod = 1e9 + 7;
const int Mxn = 1e5 + 5;
int n, m;
int c[Mxn], comp[Mxn];
vi g[Mxn], r[Mxn];
bool vis[Mxn];
stack<int> s;
int col = 0;

void dfs(int u) {
    vis[u] = 1;
    for(auto & v: g[u]) if(!vis[v]) dfs(v);
    s.push(u);
}

void dfs2(int u, int col) {
    vis[u] = 1;
    comp[u] = col;
    for(auto & v: r[u]) if(!vis[v]) dfs2(v, col);
}

void kosaraju() {
    fori(i,0,n) if(!vis[i]) dfs(i);
    memset(vis, 0, sizeof vis);
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        if(!vis[u]) {
            dfs2(u, col);
            col++;
        }
    }
}

int mn[Mxn], cnt[Mxn]; 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fori(i,0,n) cin >> c[i];
    cin >> m;
    fori(i,0,m) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        r[v].eb(u);
    }
    kosaraju();
    memset(mn, 0x3f, sizeof mn);
    fori(i,0,n) {
        if(c[i] < mn[comp[i]]) mn[comp[i]] = c[i], cnt[comp[i]] = 1;
        else if(c[i] == mn[comp[i]]) cnt[comp[i]]++;
    }
    ll price = 0, ways = 1;
    fori(i,0,col) {
        price += mn[i];
        ways *= cnt[i];
        ways %= mod;
    }
    cout << price << ' ' << ways << endl;
    return 0; 
}