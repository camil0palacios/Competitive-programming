#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 1e5 + 5;
int n, m;
vi g[Mxn];
int dp[Mxn];

bool isleaf(int u) {
    return sz(g[u]) == 0;  
}

int dfs(int u) {
    if(isleaf(u) || u == n) return u == n ? 1 : -1e9;
    if(dp[u] != -1) return dp[u];
    int ans = -1e9;
    for(auto & v: g[u]) {
        ans = max(ans, dfs(v) + 1);
    }
    return dp[u] = ans;
}

void dfs2(int u, vi & ans) {
    ans.eb(u);
    if(isleaf(u) || u == n) return;
    for(auto & v : g[u]) {
        if(dfs(u) == dfs(v) + 1) {
            dfs2(v, ans);
            return;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fori(i,0,m) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
    }
    memset(dp, -1, sizeof dp);
    int x = dfs(1);
    if(x > 0) {
        vi ans;
        dfs2(1, ans);
        cout << x << endl;
        for(auto & i : ans) cout << i << ' ';
        cout << endl;
    } else cout << "IMPOSSIBLE" << endl;
    return 0; 
}