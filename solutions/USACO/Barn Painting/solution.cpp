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
int col[Mxn];
ll dp[Mxn][3];

ll dfs(int u, int c, int p = -1) {
    if(dp[u][c] != -1) return dp[u][c];
    if(col[u] != -1 && col[u] != c) return 0;
    ll ans = 1;
    for(auto & v : g[u]) {
        if(v == p) continue;
        ans *= (dfs(v, (c+1)%3, u) + dfs(v, (c+2)%3, u)) % mod;
        ans %= mod;
    }
    return dp[u][c] = ans;
}

// dp[u][i] =  mult(sum(dp[v][j] j != i)) v E ch(u)

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    fori(i,1,n) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    memset(col, -1, sizeof col);
    fori(i,0,k) {
        int u; cin >> u; u--;
        cin >> col[u]; col[u]--;
    }
    memset(dp, -1, sizeof dp);
    ll ans = (dfs(0, 0) + dfs(0, 1) + dfs(0, 2)) % mod;
    cout << ans << endl; 
    return 0; 
}