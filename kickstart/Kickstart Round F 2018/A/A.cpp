#include <bits/stdc++.h>
using namespace std;

int f(string s1, int n, vector<vector<int>>& p){
  int ans = 0;
  for(int i = 0; i < n ; i++){
    vector<int> a(26, 0);
    for(int j = 0; j + i < n; j++){
      a[s1[i+j] - 'A']++;
      for(int l = 1; l + j <= n ; l++){
        bool aux = true;
        int cont = 0;
        for(int k = 0; k < 26 ; k++){
          if(p[l + j][k] - p[l - 1][k] != a[k]){
            aux = false;
            break;
          }
        }
        if(aux){ans++; break;}
      }
    }
  }
  return ans;
}

int main(){
  int t,c = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    vector<vector<int>> p(n + 1,vector<int>(26,0));
    for(int i = 1; i <= n; i++){
      for(int j = 0; j < 26 ; j++){
        p[i][j] = p[i - 1][j];
      }
      p[i][s2[i - 1]-'A']++;
    }
    cout << "Case #" << c++ << ": " << f(s1, n, p) << endl;
  }
  return 0;
}
