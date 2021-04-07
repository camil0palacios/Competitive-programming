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

const ll oo = 1ll << 50;
const int Mxn = 1010;
int n, m, c;
int mi[Mxn];
vi g[Mxn];
ll dp[Mxn][Mxn];

ll dfs(int u, int d) {
    if(d == 0) return u == 0 ? 0 : -oo; 
    if(dp[u][d] != -1) return dp[u][d];
    ll ans = -oo;
    for(auto & v : g[u]) {
        ans = max(ans, dfs(v, d-1) + mi[u]);
    }
    return dp[u][d] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin >> n >> m >> c;
    fori(i,0,n) cin >> mi[i];
    fori(i,0,m) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].eb(v);
    }
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    fori(i,0,Mxn) ans = max(ans, dfs(0,i) - 1ll*c*i*i);
    cout << ans << endl;
    return 0; 
}