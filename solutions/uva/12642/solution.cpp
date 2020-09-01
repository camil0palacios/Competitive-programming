#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<bool> used;

int dfs(int node, vector<int> &g, vector<int>& t, int n = 0){
    if(used[node])return n;
    used[node] = true;
    return t[node] = dfs(g[node] - 1, g, t, n + 1);
}

int main(){
  int n;
  long long r;
  while(cin>>n>>r){
    vector<int> v(n);
    vector<int> t(n,0);
    for(auto &i : v)cin>>i;
    used.assign(n,false);
    for(int i = 0; i < n; i++)
      if(!used[i])dfs(i,v,t);
    for(int i = 0; i < n ; i++){
      int c = r % t[i];
      int j = i;
      for(int  k = 0; k < c ; k++)j = v[j] - 1;
      cout << j + 1;
      if(i < n-1)cout<< " ";
      else cout << endl;
     }
  }
  return 0;
}
