#include <bits/stdc++.h>
using namespace std;

long long dp[65][65];
string s;

long long go(int i, int j){
    if(dp[i][j] != -1)return dp[i][j];
    if(j < i)return dp[i][j] = 0;
    if(i == j)return dp[i][j] = 1;
    long long ans = go(i+1,j) + go(i,j-1) - go(i+1,j-1);
    if(s[i] == s[j])ans += 1 + go(i+1,j-1);
    return dp[i][j] = ans;
}

void solve(){
    cin >> s;
    memset(dp,-1,sizeof dp);
    cout << go(0,s.size()-1) << endl;
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