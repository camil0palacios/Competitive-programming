#include <bits/stdc++.h>
using namespace std;

int main(){

  vector<string> v;
  string s;
  int mmax = 0;
  while(getline(cin,s)){
    v.push_back(s);
    int f = s.size();
    mmax = max(mmax,f);
  }
  int flag = 0;
  cout << string(mmax + 2, '*') << endl;
  for(int i = 0; i < v.size() ; i++){
    int dif = mmax - v[i].size();
    string space;
    cout << '*';
    if(dif % 2 == 0)space = string(dif/2,' ');
    else space = string(dif/2 + flag, ' '), flag = (flag) ? 0 : 1;
    cout << space << v[i] << string(dif - space.size(),' ') << '*' << endl;
  }
  cout << string(mmax + 2, '*') << endl;
  return 0;
}
