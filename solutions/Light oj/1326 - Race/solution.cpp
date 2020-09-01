#include <bits/stdc++.h>
using namespace std;

const int mod = 10056;
int dp[1005], nCk[1005][1005];

void comb(){
    nCk[0][0] = 1;
    for(int n = 1; n < 1005; n++){
        nCk[n][0] =  nCk[n][n] = 1;
        for(int k = 1; k < n; k++){
            nCk[n][k] = (nCk[n-1][k-1] + nCk[n-1][k]) % mod; 
        }
    }
}

int go(int n){
    if(n == 0)return 1;
    if(dp[n] != -1)return dp[n];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + (nCk[n][i]*go(n-i)) % mod) % mod; 
    }
    return dp[n] = ans;
}

void solve(){
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

int main(){
    comb();
    memset(dp, -1, sizeof dp);
    go(1000);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}