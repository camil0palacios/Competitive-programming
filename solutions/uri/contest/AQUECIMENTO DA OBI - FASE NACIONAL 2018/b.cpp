#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

void solution(){
  int n;
  cin >> n;
  vector<pair<int,int>> v(n);
  vector<int> v1(n);
  for(int i = 0; i < n ; i++){
    int tmp; cin >> tmp;
    v1[i] = tmp;
    v[i] = ii(i,tmp);
  }
  sort(v.begin(), v.end(), [](ii a, ii b){
    if(a.second == b.second)return a.first > b.second;
    else return a.second > b.second;
  });
  set<int> bst;
  map<ii,string> ans;
  set<int>::iterator up;
  for(auto i : v){
    up = bst.upper_bound(i.first);
    if(up != bst.end())ans[i] = to_string(v1[*up]);
    else ans[i] = "*";
    bst.insert(i.first);
  }
  for(int i = 0 ; i < n; i++){
    cout << ans[ii(i,v1[i])] << " ";
  }
  cout << endl;
}

int main(){
  solution();
  return 0;
}
