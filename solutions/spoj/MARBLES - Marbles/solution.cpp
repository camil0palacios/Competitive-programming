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

// bars and stars problem

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    f[0] = 1;
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        if(n-k < k-1) k = n-k+1;
        if(k == 1) cout << 1 << endl;
        else {
            ll ans = 1;
            fore(i,1,k-1)
                ans = ans*(n - i) / (i);
            cout << ans << endl;
        }
        // vector<vl> dp(n+2, vl(n+2));
        // fore(i,0,n) fore(j,0,k) dp[i][j] = 0;
        // dp[0][0] = 1;
        // fore(i,1,n) {
            // dp[i][0] = dp[i][i] = 1;
        //     fore(j,1,k) 
        //         dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        // } 
        // cout << dp[n][k] << endl;
    }
    return 0; 
}