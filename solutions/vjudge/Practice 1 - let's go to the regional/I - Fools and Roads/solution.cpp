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

struct Edge {
    int v, id;
    Edge() {}
    Edge(int v, int id): v(v), id(id) {}
};

const int Mxn = 1e5 + 5;
const int Lg = 18;
int st[Mxn][Lg], lvl[Mxn];
vector<Edge> g[Mxn];
int is_lca[Mxn], is_qry[Mxn];
int ans[Mxn];

void dfs(int u = 0, int p = 0) {
    for(auto & e : g[u]) {
        int v = e.v;
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
        if(lvl[u]-(1 << i) >= lvl[v]) u = st[u][i];
    if(u == v) return u;
    forr(i,Lg-1,0) {
        if(st[u][i] != st[v][i]) {
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}

int dfs2(int u = 0, int p = 0) {
    int acc = 0;
    for(auto & e : g[u]) {
        int v = e.v, id = e.id;
        if(v == p) continue;
        int cnt = dfs2(v, u);
        ans[id] += cnt;
        acc += cnt;
    }
    return acc + is_qry[u] - is_lca[u];
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n;
    fori(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v, i);
        g[v].eb(u, i);
    }
    dfs();
    cin >> q;
    fori(i,0,q) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        is_qry[u]++, is_qry[v]++;
        is_lca[lca(u, v)] += 2;
    }
    dfs2();
    fori(i,0,n-1) cout << ans[i] << ' ';
    cout << endl;
    return 0; 
}