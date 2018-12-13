#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<string,int> cc;
  while(n--){
    string s;
    cin >> s;
    if(cc.count(s) == 0){
      cout << "OK" << endl;
      cc.insert({s,0});
    }
    else{
      cc[s]++;
      cout << s << cc[s] << endl;
    }
  }
  return 0;
}
