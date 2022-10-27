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

// dont forget de max value of n and log of n
const int Mxn = 2e5 + 5;
const int Lg = 18;
vi g[Mxn];
int st[Mxn][Lg], lvl[Mxn];

void dfs(int u, int p) {
    for(auto & v : g[u]) {
        if(v == p) continue;
        lvl[v] = lvl[u] + 1;
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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,1,n) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(0, 0);
    fori(i,0,m) {
        int k;
        cin >> k;
        int v[k], mx = 0, u = 0;
        fori(j,0,k) {
            cin >> v[j];
            v[j]--;
            if(mx < lvl[v[j]]) mx = lvl[v[j]], u = v[j];
        }
        bool ok = 1;
        fori(j,0,k) {
            int p = st[v[j]][0];
            ok &= lca(u, v[j]) == v[j] || lca(u, p) == p; 
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}