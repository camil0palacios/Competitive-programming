#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    long long s, a, b, c;
    cin >> s >> a >> b >> c;
    long long cb = s/c, x;
    if(cb < a)x = 0;
    else x = (cb/a) * b;
    cout << cb + x << endl;
  }
  return 0;
}
