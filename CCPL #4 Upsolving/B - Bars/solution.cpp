#include <bits/stdc++.h>
using namespace std;

int n, k, a[25], dp[25][1005];

int go(int idx, int acc){
    if(idx == n)return (acc == k ? 1 : 0);
    if(dp[idx][acc] != -1)return dp[idx][acc];
    int ans = go(idx+1,acc);
    if(acc + a[idx] <= k)ans |= go(idx+1,acc + a[idx]);
    return dp[idx][acc] = ans;
}

void solve(){
    cin >> k >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    if(go(0,0)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}