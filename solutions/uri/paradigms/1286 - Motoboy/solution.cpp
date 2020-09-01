#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct nodo{
  long long t, p;
  nodo(){}
  nodo(long long _t, long long _p): t(_t), p(_p){}
};

long long dp[21][31];
typedef vector<nodo> vn;

long long recurse(vn &v, int idx, int total){
  if(idx == v.size() || total == 0)return 0;
  if(dp[idx][total] != -1)return dp[idx][total];
  long long ans = 0;
  if(v[idx].p > (long long)total)ans = recurse(v, idx + 1, total);
  else ans = max(recurse(v, idx + 1, total), recurse(v, idx + 1, total - v[idx].p) + v[idx].t);
  return dp[idx][total] = ans;
}

int main(){
  int t;
  while(cin >> t && t != 0){
    int n;
    cin >> n;
    vector<nodo> v(t);
    for(auto &i : v)cin >> i.t >> i.p;
    memset(dp, -1, sizeof dp);
    cout << recurse(v,0,n) << " min." << endl;
  }
  return 0;
}
