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

const int mod = 1e9 + 7;
const int Mxn = 1e5 + 5;
vi g[Mxn];
ll dp[Mxn][2];

void dfs(int u, int p = 0) {
    dp[u][0] = dp[u][1] = 1;
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1]) % mod) % mod;
        dp[u][1] = (dp[u][1] * dp[v][0]) % mod;
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
    dfs(0);
    ll ans = (dp[0][0] + dp[0][1]) % mod;
    cout << ans << endl;
    return 0;
}