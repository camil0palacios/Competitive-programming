#include <bits/stdc++.h>
using namespace std;

string s1, s2, mes[105][105];
int dp[105][105];

int go(int i, int j){
    if(i == s1.size() || j == s2.size()){
        mes[i][j] = "";
        return dp[i][j] = 0;
    }
    if(dp[i][j] != -1)return dp[i][j];
    string s;
    int ans = 0;
    if(s1[i] == s2[j]){
        ans = 1 + go(i+1,j+1);
        s = s1[i] + mes[i+1][j+1];
    }else{
        ans = max(go(i+1,j),go(i,j+1));
        if(dp[i+1][j] < dp[i][j+1]){
            s = mes[i][j+1];
        }else if(dp[i+1][j] > dp[i][j+1]){
            s = mes[i+1][j];
        }else{
            s = min(mes[i+1][j],mes[i][j+1]);
        }
    }
    mes[i][j] = s;
    return dp[i][j] = ans;
}

void solve(){
    cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i <= s1.size(); i++){
        mes[i][0].clear();
    }
    for(int i = 0; i <= s2.size(); i++){
        mes[0][i].clear();
    }
    cout << (go(0,0) ? mes[0][0] : ":(" ) << endl;
}

int main(){
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}