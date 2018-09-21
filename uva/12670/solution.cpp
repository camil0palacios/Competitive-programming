#include <bits/stdc++.h>
using namespace std;

typedef bitset<54> bits;

long long dp[55][2][55];

long long f(string &num, int indx, bool top, int acc = 0){
  if(indx == num.size())return acc;
  if(dp[indx][top][acc] != -1)return dp[indx][top][acc];
  long long res = 0;
  int mmax = (top ? (num[indx] - '0') : 1);
  for(int j = 0 ;  j <= mmax ; j++){
    res += f(num, indx + 1, top && (j == mmax), acc + (j == 1));
  }
  return dp[indx][top][acc] = res;
}

int main(){
  long long a,b;
  while(cin >> a >> b){
    string num = bits(b).to_string();
    memset(dp, -1, sizeof(dp));
    long long ans = f(num, 0, true);
    num = bits(a - 1).to_string();
    memset(dp, -1, sizeof(dp));
    ans -= f(num, 0, true);
    cout << ans << endl;
  }
  return 0;
}
