#include <bits/stdc++.h>
using namespace std;

int dp[21][(1<<3)+5], a[21][3], n;

int go(int idx, int mask){
    if(idx == n)return 0;
    if(dp[idx][mask] != -1)return dp[idx][mask];
    int ans = 1e9;
    for(int j = 0; j < 3; j++){
        if(!((mask>>j)&1)){
            ans = min(ans, go(idx+1,(1<<j)) + a[idx][j]);
        }
    }
    return dp[idx][mask] = ans;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(0,0) << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
}