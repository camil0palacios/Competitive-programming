#include <bits/stdc++.h>
using namespace std;

long long dp[65][10];
/*
long long go(int idx, int last){
    if(idx == 0)return 1;
    if(dp[idx][last] != -1)return dp[idx][last];
    long long ans = 0;
    for(int i = 0; i <= 9; i++){
        if(i >= last){
            ans += go(idx - 1, i);
        }
    }
    return dp[idx][last] = ans;
}
*/

long long it_dp(int n){
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < 10; i++){
        dp[0][i] = 1;
    }
    for(int idx = 1; idx <= n; idx++){
        for(int last = 0; last < 10; last++){
            for(int i = 0; i < 10; i++){
                if(i >= last){
                    dp[idx][last] += dp[idx - 1][i];
                }
            }
        }
    }   
    return dp[n][0];
}

void solve(){
    int n;
    cin >> n >> n;
    //memset(dp, -1, sizeof dp);
    //cout << go(n,0) << endl;
    cout << it_dp(n) << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << i << " ";
        solve();
    }
}