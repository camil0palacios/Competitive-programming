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

const ll mod = 1e9 + 7;
const int Mxn = 110;
const int Mxk = 100010;
int a[Mxn];
ll dp[Mxn][Mxk];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;   
    fori(i,0,n) cin >> a[i];
    // dp[i][k] += dp[i+1][k - j] 0 <= j <= min(a[i], k)
    // dp[n-1][k] += dp[n][k] + dp[n][k - 1] + dp[n][k-2] + dp[n][k-2] + ... + dp[n][k - min(a[i], k)]
    dp[n][0] = 1;
    for(int i = n-1; i >= 0; i--) {
        vll p(k + 2);
        for(int j = 0; j <= k; j++) p[j+1] = (p[j] + dp[i+1][j]) % mod;
        for(int j = 0; j <= k; j++) 
            // if(a[i] <= j) dp[i][j] = (p[j + 1] - p[j - a[i]] + mod) % mod;
            // else dp[i][j] = p[j + 1];
            dp[i][j] = (p[j + 1] - p[j - min(a[i], j)] + mod) % mod;
    }
    cout << dp[0][k] << endl;
    return 0; 
}