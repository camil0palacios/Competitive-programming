#include <bits/stdc++.h>
using namespace std;

int f(vector<int> v, int k){
  int indx = 0;
  do{
    v.erase(v.begin() + indx);
    indx = (indx - 1 + k) % v.size() ;
  }while(v.size() > 1);

  return v[0];
}

int main(){
  int n;
  while(cin >> n && n){
    vector<int> v(n);
    for(int i = 0; i < n; i++)v[i] = i + 1;
    int i, ans = 0;
    for(i = 1; ans != 13 ; i++)
      ans = f(v,i);
    cout << i - 1 << endl;
  }
  return 0;
}
