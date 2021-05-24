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
const int Lg = 18;
const int Sq = 318;
int a[Mxn];
vi g[Mxn];
int d[Mxn], st[Mxn][Lg];
int in[Mxn], out[Mxn];
int t[3*Mxn], ti = 0;

void dfs(int u = 0, int p = 0) {
    t[ti] = u;
    in[u] = ti++;
    for(auto & v : g[u]) {
        if(v == p) continue;
        d[v] = d[u] + 1;
        st[v][0] = u;
        fori(i,1,Lg) st[v][i] = st[st[v][i-1]][i-1];
        dfs(v, u);
    }
    t[ti] = u;
    out[u] = ti++;
}

int lca(int a, int b) {
    if(d[a] > d[b]) swap(a, b);
    forr(i,Lg-1,0) {
        if(d[a] - (1 << i) >= d[b]) {
            a = st[a][i];
        }
    }
    if(a == b) return a;
    forr(i,Lg-1,0) {
        if(st[a][i] != st[b][i]) {
            a = st[a][i];
            b = st[b][i];
        }
    }
    return st[a][0];
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
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
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;
        int lc = lca(u, v);
        if(d[u] > d[v]) swap(u, v);
        q.eb(lc != u ? out[u] : in[u], in[v], lc, k, i);
    }
    mos(q);
    fori(i,0,m) cout << ans[i] << endl;
    return 0; 
}