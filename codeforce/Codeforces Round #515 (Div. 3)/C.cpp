#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int q;
  cin >> q;
  vector<int> v(200000,0);
  char c;
  int i, l = 0, r = 0;
  cin >> c >> i;
  while(--q){
    cin >> c >> i;
    if(c == 'L'){
      l--;
      v[i] = l;
    }
    else if(c == 'R'){
      r++;
      v[i] = r;
    }
    else cout << min(v[i] - l, r - v[i]) << endl;
  }

  return 0;
}
