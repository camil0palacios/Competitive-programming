#include <bits/stdc++.h>
using namespace std;
 
string a, b;
int dp[32][32];
long long _dp[32][32][32];
 
int lcs(int i, int j){
    if(i >= a.size() || j >= b.size())return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
    if(a[i] == b[j])ans = 1 + lcs(i+1,j+1);
    else ans = max(lcs(i+1,j),lcs(i,j+1));
    return dp[i][j] = ans;
}
 
long long go(int i, int j, int k){
    if(i >= a.size() && j >= b.size() && k == 0)return 1;
    if(_dp[i][j][k] != -1)return _dp[i][j][k];
    long long ans = 0;
    if(i < a.size() && j < b.size() && k > 0 && a[i] == b[j])ans += go(i+1,j+1,k-1);
    else{
        if(i < a.size())ans += go(i+1,j,k);
        if(j < b.size())ans += go(i,j+1,k);
    }
    return _dp[i][j][k] = ans;
}
 
void solve(){
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    int k = lcs(0,0);
    memset(_dp, -1, sizeof _dp);
    long long ans = go(0,0,k);
    cout << a.size() + b.size() - k << " " << ans << endl;
}
 
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <=  t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}