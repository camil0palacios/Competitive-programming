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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 2e5 + 5;
const int Lg = 19;
vi g[N];
bool vis[N];
int st[N][Lg], d[N];

void dfs(int u, int p) {
    for(auto v : g[u]) {
        if(v == p) continue;
        d[v] = d[u] + 1;
        st[v][0] = u;
        fori(i,1,Lg) st[v][i] = st[st[v][i-1]][i-1];
        dfs(v, u);
    }
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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n;
    fori(i,0,n) g[i].clear();
    fori(i,1,n) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(0, 0);
    cin >> q;
    while(q--) {
        int k; cin >> k;
        vi p(k);
        fori(i,0,k) {
            vis[i] = 0;
            cin >> p[i], p[i]--;
        }
        sort(all(p), [&](int i, int j) { return d[i] > d[j]; });
        fori(i,0,k) {
            if(lca(p[0], p[i]) == p[i]) vis[i] = 1;
        }
        int j = 0;
        while(j < k && vis[j]) j++;
        if(j == k) {
            cout << "YES" << endl;
            continue;
        }
        fori(i,j,k) {
            if(lca(p[j], p[i]) == p[i]) vis[i] = 1;
        }
        bool ans = 1;
        fori(i,0,k) ans &= vis[i];
        ans &= d[lca(p[0], p[j])] <= d[p.back()];
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0; 
}