#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a, b) for (int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; only for extreme cases
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;
vii g[Mxn];
int node_u[Mxn], vis[Mxn], in[Mxn], out[Mxn];
int ans[Mxn];

void dfs(int u, bool d) {
    vis[u] = 1;
    for(auto &e : g[u]) {
        int v = e.ft, id = e.sd;
        if(u == node_u[id]) ans[id] = d;
        else ans[id] = d ^ 1;
        if(d) in[u]++, out[v]++;
        else in[v]++, out[u]++; 
        if(!vis[v]) dfs(v, d ^ 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        node_u[i] = u;
        g[u].eb(v, i);
        g[v].eb(u, i);
    }
    dfs(0, 0);
    int ok = 1;
    fori(i,0,n) ok &= !(in[i] && out[i]);
    if(ok) {
        cout << "YES" << endl;
        fori(i,0,m) cout << ans[i];
        cout << endl;
    } 
    else cout << "NO" << endl;
    return 0;
}