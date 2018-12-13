#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  while(cin >> t , t){
    int n, m;
    cin >> n >> m;
    while(t--){
      int x, y;
      cin >> x >> y;
      if(n == x || m == y)cout << "divisa" << endl;
      else if(x > n && y > m)cout << "NE" << endl;
      else if(x < n && y > m)cout << "NO" << endl;
      else if(x < n && y < m)cout << "SO" << endl;
      else cout << "SE" << endl;
    }
  }

  return 0;
}
