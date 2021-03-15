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
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator<(const Edge & e) { return w < e.w; }
};

struct Dsu {
    vi p, size;
    Dsu(int n) { p.resize(n); size.resize(n); fori(i,0,n) p[i] = i, size[i] = 1; }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    bool join(int a, int b) { 
        a = find(a), b = find(b);
        if(a == b) return 0;
        size[a] += size[b];
        p[b] = a;
        return 1;
    } 
    int get_size(int u) { return size[find(u)]; }
};

pair<vector<Edge>, int> mst(int n, vector<Edge> & edges, bool op) {
    sort(all(edges));
    if(op) reverse(all(edges));
    Dsu ds(n);
    vector<Edge> t;
    int btn = 0;
    for(auto & e : edges) {
        int u = e.u, v = e.v, w = e.w;
        if(ds.join(u, v)) {
            t.eb(u, v, w);
            btn = w;         
        }
    }
    return mp(t, btn);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Edge> e(m);
    fori(i,0,m) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u--, e[i].v--;
    }
    int btn = mst(n, e, 1).sd;
    vector<Edge> et;
    fori(i,0,m) {
        if(e[i].w >= btn) et.eb(e[i].u, e[i].v, e[i].w);
    } 
    e = et;
    vector<Edge> t = mst(n, e, 0).ft;
    sort(all(t));
    reverse(all(t));
    Dsu ds(n);
    ll ans = 0;
    for(auto & e : t) {
        int u = e.u, v = e.v, w = e.w;
        ans += 1ll*ds.get_size(u)*ds.get_size(v)*w;
        ds.join(u, v);
    }
    cout << ans << endl;
    return 0; 
}