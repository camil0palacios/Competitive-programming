#include <bits/stdc++.h>
using namespace std;
 
int n, dp[201][201];
 
int go(vector<vector<int> > & a, int i, int j){
    if (j < 0 || i == 2*n-1 || j >= a[i].size())return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = go(a,i+1,j);
    if(i < n-1)ans = max(ans, go(a,i+1,j+1));
    else ans = max(ans, go(a,i+1,j-1));
    return dp[i][j] = ans + a[i][j];
}
 
void solve(){
    cin >> n;
    vector<vector<int> > a(2*n-1);
    int x = 1, tmp;
    bool flag = 1;
    for(int i = 0; i < 2*n-1; i++){
        for(int j = 0; j < x; j++){
            cin >> tmp;
            a[i].push_back(tmp);
        }
        if(x == n)flag = 0;
        if(flag)x++;
        else x--;
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