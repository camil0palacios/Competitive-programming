#include <bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin >> t;
  while(t--){
    int n, mmax = 0, mmin = 99;
    cin >> n;
    while(n--){
      int tmp;
      cin >> tmp;
      mmin = min(mmin, tmp);
      mmax = max(mmax, tmp);
    }
    cout << 2*(mmax - mmin) << endl;
  }

  return 0;
}
