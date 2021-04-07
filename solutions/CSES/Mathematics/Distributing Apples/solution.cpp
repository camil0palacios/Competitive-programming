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
const int Mxn = 2e6 + 1;
ll f[Mxn], fi[Mxn];

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans*a) % mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    return ans;
}

int C(int n, int r) {
    return ((f[n] * fi[r]) % mod) * fi[n-r] % mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    f[0] = fi[0] = 1;
    fori(i,1,Mxn) {
        f[i] = (f[i-1]*i) % mod;
        fi[i] = be(f[i], mod-2);
    } 
    int n, m;
    cin >> n >> m;
    cout << C(n+m-1,n-1) << endl;
    // basic idea
    // dp[n][m] += dp[n-1][j] 0 <= j <= m
    // int dp[n+1][m+1];
    // memset(dp, 0, sizeof dp);
    // dp[0][0] = 1;
    // fore(i,1,n) fore(j,0,m) {
    //     dp[i][j] = dp[i-1][j];
    //     if(j) dp[i][j] += dp[i][j-1];
    // }
    // cout << dp[n][m] << endl;
    return 0; 
}