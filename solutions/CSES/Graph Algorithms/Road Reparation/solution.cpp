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

const int Mxn = 2e5 + 5;
int p[Mxn];

struct Edge {
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
bool join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        p[b] = a;
        return 1;
    }
    return 0;
}

ll kruskal(vector<Edge> & edges) {
    sort(all(edges), [](Edge e1, Edge e2) { return e1.w < e2.w; });
    ll ans = 0;
    for(auto & e : edges) {
        if(join(e.u, e.v)) ans += e.w;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    fori(i,0,n) p[i] = i;
    fori(i,0,m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.eb(u, v, w);
        edges.eb(v, u, w);
    }
    ll ans = kruskal(edges);
    set<int> s;
    fori(i,0,n) s.insert(find(i));
    if(sz(s) == 1) cout << ans << endl; 
    else cout << "IMPOSSIBLE" << endl;
    return 0; 
}