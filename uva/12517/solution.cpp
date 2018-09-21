#include <bits/stdc++.h>
using namespace std;

long long dp[10][2][100];

long long f(string &num, int indx, bool top, int acc = 0){
  if(indx == num.size())return acc;
  if(dp[indx][top][acc] != -1)return dp[indx][top][acc];
  long long ans = 0;
  int mmax = (top ? num[indx] - '0' : 9);
  for(int j = 0 ; j <= mmax ; j++)
    ans += f(num, indx + 1, top && (j == mmax), acc + j);
  return dp[indx][top][acc] = ans;
}

int main(){
  long long n, m;
  while(cin >> n >> m && (n + m)){
    string a = to_string(m);
    memset(dp, -1, sizeof(dp));
    long long ans = f(a, 0, true);
    string b = to_string(n - 1);
    memset(dp, -1, sizeof(dp));
    ans -= f(b, 0, true);
    cout << ans << endl;
  }
  return 0;
}
