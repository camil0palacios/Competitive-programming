#include <bits/stdc++.h>
using namespace std;

string s;
int n, dp[101][101];

int go(int l, int r){
    if(l >= r)return 0;
    if(dp[l][r] != -1)return dp[l][r];
    int ans = 0;
    if(s[l] == s[r]){
        ans = go(l+1,r-1);
    }else{
        ans = 1 + min(go(l+1,r),go(l,r-1));
    }
    return dp[l][r] = ans;
}

void solve(){
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << go(0, (int)s.size()-1) << endl;
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