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
struct Edge { int v, t; Edge(){} Edge(int v, int t): v(v), t(t) {} };
vector<Edge> g[Mxn];
int mrk[Mxn], d[Mxn], p[Mxn];
bool vis[Mxn];

void dfs(int u = 0, int x = 0) {
    if(x == 2) mrk[u] = 1;
    for(auto & e : g[u]) {
        int v = e.v, t = e.t;
        if(v == p[u]) continue;
        d[v] = d[u]+1;
        p[v] = u;
        dfs(v, t);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n-1) {
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        g[u].eb(v, t);
        g[v].eb(u, t);
    }
    dfs();
    vii v;
    fori(i,0,n) if(mrk[i]) v.eb(d[i], i);
    sort(all(v), greater<ii>());
    vi ans;
    for(auto & x : v) {
        if(!vis[x.sd]) {
            for(int u = x.sd; u != 0 && !vis[u]; u = p[u]) vis[u] = 1;
            ans.eb(x.sd);
        }
    }
    cout << sz(ans) << endl;
    for(auto & i : ans) cout << i+1 << ' ';
    cout << endl;
    return 0; 
}