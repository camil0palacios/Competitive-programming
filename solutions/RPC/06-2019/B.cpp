#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, p;
const int tam = 205;
const int mod = 1e9+7;
long long dp[tam][(tam*(tam+1))/2];

long long preprocess(){
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int idx = 1; idx <= n; idx++){
        for(int sum = 0; sum <= p; sum++){
            dp[idx][sum] = dp[idx-1][sum];
            if(sum - idx >= 0){
                dp[idx][sum] += dp[idx-1][sum-idx];
                dp[idx][sum] %= mod;
            }
        }
    }
    return dp[n][p];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    n = 200; p = (n*(n+1))/2;
    preprocess();
    int q;
    cin >> q;
    while(q--) {
        cin >> n >> p;
        cout << dp[n][p] << endl;
    }
    return 0;
}