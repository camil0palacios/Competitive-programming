#include <bits/stdc++.h>
using namespace std;

bool dp_pre[1001][1001];
int dp[1001], n;

int go(int idx){
    if(idx == n)return 0;
    if(dp[idx] != -1)return dp[idx];
    int ans = 1e9;
    for(int j = 0; idx + j < n; j++){
        if(dp_pre[idx][idx+j]){
            ans = min(ans, go(idx+j+1) + 1);
        }   
    }
    return dp[idx] = ans;
}

void solve(){
    string s;
    cin >> s;
    n = (int)s.size();
    memset(dp_pre, 0, sizeof dp_pre);
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1])dp_pre[i][i+1] = 1;
        dp_pre[i][i] = 1;
    }
    dp_pre[n-1][n-1] = 1;
    for(int j = 2; j < n; j++){
        for(int i = 0; i + j < n; i++){
            if(s[i] == s[i+j] && dp_pre[i+1][i+j-1]){
                dp_pre[i][i+j] = 1;
            }
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