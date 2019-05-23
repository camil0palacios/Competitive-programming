#include <bits/stdc++.h>
using namespace std;

int dp[(1<<15)+10], a[15][15], n;

int go(int mask){
    if(mask == (1<<n)-1)return 0;
    if(dp[mask] != -1)return dp[mask];
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        if(((mask >> i)&1) == 0){
            int sum = a[i][i];
            for(int j = 0; j < n; j++){
                if(i != j && ((mask>>j)&1)){
                    sum += a[i][j];
                }
            }
            ans = min(ans, go(mask|(1 << i)) + sum);
        }
    }
    return dp[mask] = ans;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(0) << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    } 
    return 0;
}