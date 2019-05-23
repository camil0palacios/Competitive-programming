#include <bits/stdc++.h>
using namespace std;

int const NM = 1e5 + 5;
const long long m = 100000007;
long long dp[NM];
int n, k, c;

void solve(){
    cin >> n >> k;
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> c;
        for(int j = c; j <= k; j++){
            dp[j] += dp[j-c];
            dp[j] = dp[j] % m;
        }
    }
    cout << dp[k] << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " <<  i << ": ";
        solve();
    }
    return 0;
}