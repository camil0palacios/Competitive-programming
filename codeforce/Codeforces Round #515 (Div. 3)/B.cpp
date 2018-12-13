#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, r;
  cin >> n >> r;
  vector<int> v(n,-1);
  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    if(tmp == 1){
      int inf = ((i - r + 1 <= 0)? 0 : i - r + 1), sup = i + r - 1 ;
      for(int j = inf; (j <= sup) && (j < n); j++){
        v[j] = i;
      }
    }
  }
  int ans = 0;
  bool flag = 1;
  for(int i = 0; i < n; i += r){
    if(v[i] > -1){
      i = v[i];
      ans++;
    }
    else{
      flag = 0;
      break;
    }
  }
  if(flag)cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}
