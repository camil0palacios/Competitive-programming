#include <bits/stdc++.h>
using namespace std;

int inf = 999999;

int ans(vector<int> &v, int n, int m){
  int dp[m + 1];
  memset(dp,inf,sizeof dp);
  dp[0] = 0;
  for(int i = 0; i < n ; i++)
    for(int j = v[i]; j <= m ; j++){
      dp[j] = min(dp[j], dp[j - v[i]] + 1);
    }
  return dp[m];
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    cout << ans(v,n,m) << endl;
  }
  return 0;
}
