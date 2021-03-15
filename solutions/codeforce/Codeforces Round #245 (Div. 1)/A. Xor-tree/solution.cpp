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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 1e5 + 5;
vi g[Mxn];
bool init[Mxn], goal[Mxn];
int depth[Mxn];
int ans;
unordered_set<int> s;

void dfs(int u, int p = -1, int e = 0, int o = 0) {
    if(depth[u] & 1) {
        if(o & 1) init[u] ^= 1;
        if(goal[u] != init[u]) ans++, o++, s.insert(u);
    } else {
        if(e & 1) init[u] ^= 1;
        if(goal[u] != init[u]) ans++, e++, s.insert(u);
    }
    for(auto & v : g[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u, e, o);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n-1) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    fori(i,0,n) cin >> init[i];
    fori(i,0,n) cin >> goal[i];
    dfs(0);
    cout << ans << endl;
    for(auto & u : s) cout << u + 1 << endl;
    return 0; 
}