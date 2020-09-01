#include <iostream>
#include <vector>
using namespace std;

void base(int n, int b, vector<int> & v){
  while(n){
    int x = n % b;
    v.emplace_back(x);
    n /= b;
  }
}

int main(){
  int t, b, x, y;
  cin >> t;
  for(int i = 1; i <= t; i++){
      cout << i << " ";
      cin >> b >> b >> x >> y;
      vector<int> v1, v2, ans;
      base(x,b,v1);
      base(y,b,v2);
      int top = min(v1.size(), v2.size());
      for(int i  = 0; i < top; i++){
        int tmp = (v1[i] + v2[i]) % b;
        ans.emplace_back(tmp);
      }
      top = max(v1.size(), v2.size());
      for(int i = min(v1.size(), v2.size()); i < top; i++){
        if(v1.size() < v2.size()){
          ans.emplace_back(v2[i]);
        }
        else ans.emplace_back(v1[i]);
      }
      int pot = 1, res = 0;
      for(int i = 0; i < ans.size(); i++){
        res += ans[i]*pot;
        pot *= b;
      }
      cout << res << endl;
  }
  return 0;
}