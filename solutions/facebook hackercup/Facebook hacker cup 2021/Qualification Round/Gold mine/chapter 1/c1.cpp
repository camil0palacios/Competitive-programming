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

const int Mxn = 55;
const int Lg = 7;
int n, c[Mxn];
vi g[Mxn];
int st[Mxn][Lg], lvl[Mxn];

void dfs(int u, int p) {
    for(auto & v : g[u]) {
        if(v == p) continue;
        lvl[v] = lvl[u] + 1;
        c[v] += c[u];
        st[v][0] = u;
        fori(i,1,Lg) st[v][i] = st[st[v][i-1]][i-1];
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(lvl[u] < lvl[v]) swap(u, v);
    forr(i,Lg-1,0)
        if(lvl[u] - (1 << i) >= lvl[v]) u = st[u][i];
    if(u == v) return u;
    forr(i,Lg-1,0) {
        if(st[u][i] != st[v][i]) {
            u = st[u][i];
            v = st[v][i];
        } 
    }
    return st[u][0];
}

int dist(int u, int v) {
    return lvl[u] + lvl[v] - 2*lvl[lca(u, v)];
}

int ans;

void dfs2(int u, int p) {
    ans = max(ans, c[u]);
    fori(v,0,n) {
        if(u == v) continue;
        int _lca = lca(u, v);
        if(_lca == u || _lca == v) continue;
        if(_lca == 0) {
            ans = max(ans, c[u] + c[v] - c[0]);
        }
    }
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs2(v, u);
    }
}

void clear(int n) {
    fori(i,0,n) {
        g[i].clear();
        c[i] = lvl[i] = 0;
        fori(j,0,Lg) st[i][j] = 0;
    }
}

void solve() {
    cin >> n;
    clear(n);
    fori(i,0,n) cin >> c[i];
    fori(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(0, 0);
    ans = 0;
    dfs2(0, 0);
    cout << ans << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}