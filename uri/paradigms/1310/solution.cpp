#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &v, int n){
  int dp[n + 1]; dp[0] = 0;
  int mmax = 0;
  for(int i = 1; i <= n; i++){
    dp[i] = max(v[i] , v[i] + dp[i - 1]);
    mmax = max(mmax,  dp[i]);
  }
  return ( mmax <= 0 ? 0 : mmax);
}

int main(){
  int n;
  while(cin >> n){
    int m;
    cin >> m;
    vector<int> v(n), v1(n + 1); v1[0] = 0;
    for(auto &i : v)cin >> i;
    for(int i = 1; i <= n ; i++) v1[i] = v[i - 1] - m;
    cout << kadane(v1,n) << endl;
  }
  return 0;
}
