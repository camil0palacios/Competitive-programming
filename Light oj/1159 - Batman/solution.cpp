#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int dp[51][51][51];

int go(int i, int j, int k){
    if(i == (int)a.size() || j == (int)b.size() || k == (int)c.size())return 0;
    if(dp[i][j][k] != -1)return dp[i][j][k];
    int ans = 0;
    if(a[i] == b[j] && b[j] == c[k]){
        ans = 1 + go(i+1,j+1,k+1);
    }else{
        ans = max(go(i+1,j,k),max(go(i,j+1,k),go(i,j,k+1)));
    }
    return dp[i][j][k] = ans;
}

void solve(){
    cin >> a >> b >> c;
    memset(dp, -1, sizeof dp);
    cout << go(0,0,0) << endl;
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