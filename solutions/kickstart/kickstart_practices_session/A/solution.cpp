#include <bits/stdc++.h>
using namespace std;

int main(){
  int t,caso = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n ; i++){
      cin >> a[i] >> b[i] ;
    }
    int p;
    cin >> p;
    vector<int> ans(p,0),cities(p);
    for(auto &i : cities)cin >> i;
    for(int i = 0; i < n ; i++){
      for(int i = 0; i < cities.size() ; i++){
        if(cities[i] >= a[i] && cities[i] <= b[i])ans[i]++;
      }
    }
    cout << "Case #"<< caso ++ <<": ";
    for(int i = 0; i < ans.size(); i++){
      cout << ans[i];
      if(i < ans.size() - 1)cout <<" ";
      else cout << endl;
    }
    string tmp;
    getline(cin,tmp);
  }
  return 0;
}
