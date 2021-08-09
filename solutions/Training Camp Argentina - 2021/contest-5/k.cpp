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

const int Mxn = 2020;
int c[Mxn][Mxn];
vii g[Mxn];
int d[Mxn][Mxn], r;
int p[Mxn];

int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
bool join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        p[b] = a;
        return 1;
    }
    return 0;
}

void dfs(int u, int p, int acc) {
    for(auto & e : g[u]) {
        int v = e.ft, w = e.sd;
        if(v == p) continue;
        d[r][v] = acc + w;
        dfs(v, u, acc + w); 
    }
}

void mst(vector<pair<int,ii>> & edges) {
    sort(all(edges));
    for(auto & e : edges) {
        int w = e.ft, u = e.sd.ft, v = e.sd.sd;
        if(join(u, v)) {
            g[u].eb(v,w);
            g[v].eb(u,w);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) p[i] = i;
    vector<pair<int,ii>> edges;
    fori(i,0,n) {
        fori(j,0,n) {
            cin >> c[i][j];
            if(i != j && c[i][j]) edges.eb(c[i][j], mp(i, j));
        }
    }
    mst(edges);
    fori(i,0,n) {
        r = i;
        dfs(i, i, 0);
    }
    bool ok = 1;
    fori(i,0,n) {
        fori(j,0,n) {
            ok &= find(i) == find(j);
            ok &= c[i][j] == d[i][j];
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
    return 0; 
}