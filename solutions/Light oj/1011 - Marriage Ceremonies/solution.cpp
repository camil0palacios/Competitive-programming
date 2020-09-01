#include <bits/stdc++.h>
using namespace std;

int dp[17][(1 << 16)], n;

int go(vector<vector<int>> & a, int idx, int mask){
    if(idx == n)return 0;
    if(dp[idx][mask] != -1)return dp[idx][mask];
    int ans = 0;
    for(int j = 0; j < n; j++){
        if(((mask >> j)&1) == 0){
            ans = max(ans, go(a,idx+1,mask|(1<<j)) + a[idx][j]);
        }
    }
    return dp[idx][mask] = ans;
}

void solve(){
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(a,0,0) << endl;
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