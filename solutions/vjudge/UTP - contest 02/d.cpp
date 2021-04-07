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

const int Sq = 448;
const int Lg = 17;
const int Mxn = 1e5 + 5;
vi g[Mxn];
int a[Mxn];
int blc[Mxn];
int d[Mxn], st[Mxn][Lg], L[Mxn], R[Mxn];
int t[2*Mxn], ti = 0;
int vis[Mxn], c[Mxn], ans[2*Mxn];

void clear(int n) {
    ti = 0;
    fore(i,0,n) {
        g[i].clear();
        vis[i] = c[i] = ans[i] = 0;
    }
}

void dfs(int u = 0, int p = 0) {
    t[++ti] = u;
    L[u] = ti;
    for(auto & v: g[u]) {
        if(v == p) continue;
        d[v] = d[u] + 1;
        st[v][0] = u;
        fori(i,1,Lg) st[v][i] = st[st[v][i-1]][i-1];
        dfs(v, u);
    }
    t[++ti] = u;
    R[u] = ti;  
}

int lca(int u, int v) {
    if(d[u] < d[v]) swap(u, v);
    forr(i,Lg-1,0) {
        if(d[u] - (1 << i) >= d[v]) u = st[u][i];
    }
    if(u == v) return u;
    forr(i,Lg-1,0) {
        if(st[u][i] != st[v][i]) {
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}

struct Query {
    int l, r, i, lc, c;
    Query(){}
    Query(int l, int r, int i, int lc, int c): 
        l(l), r(r), i(i), lc(lc), c(c) {}
    bool operator<(const Query & q) {
        return mp(l/Sq, r) < mp(q.l/Sq, q.r); 
    }
};

void check(int x) {
    if(!vis[x]) c[a[x]]++;
    else c[a[x]]--;
    vis[x] ^= 1;
}

void mo(vector<Query> & Q) {
    sort(all(Q));
    int l = 1, r = 0;
    for(auto & q : Q) {
        while(l < q.l) check(t[l++]);
        while(l > q.l) check(t[--l]);
        while(r < q.r) check(t[++r]);
        while(r > q.r) check(t[r--]);
        int u = t[l], v = t[r];
        if(u != q.lc && v != q.lc) check(q.lc);
        ans[q.i] = c[q.c] ? 1 : 0;
        if(u != q.lc && v != q.lc) check(q.lc);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    bool ok = 0;
    while(cin >> n) {
        if(ok) cout << endl;
        cin >> m;
        clear(n);
        fori(i,0,n) cin >> a[i];
        fori(i,0,n-1) {
            int u, v; 
            cin >> u >> v;
            u--, v--;
            g[u].eb(v);
            g[v].eb(u);
        }
        dfs();
        vector<Query> q;
        fori(i,0,m) {
            int u, v, val;
            cin >> u >> v >> val;
            u--, v--;
            if(d[u] > d[v]) swap(u, v);
            int lc = lca(u, v);
            q.eb(lc == u ? L[u] : R[u], L[v], i, lc, val);
        }
        mo(q);
        fori(i,0,m) cout << (ans[i] ? "Find" : "NotFind") << endl;
        ok = 1;
    }
    return 0; 
}