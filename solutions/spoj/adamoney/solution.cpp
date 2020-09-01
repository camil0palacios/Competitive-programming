#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> mat;
const int N = 5;
const long long mod = 1e9 + 7;

mat operator*(mat x, mat y){
  mat z(N, vector<long long> (N,0));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++){
        z[i][j] = (z[i][j] + (x[i][k]*y[k][j]) % mod) % mod;
      }
    }
  }
  return z;
}

mat identidad(){
  mat id = {{1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1}};
  return id;
}

mat binpow(mat a, long long b) {
    mat res = identidad();
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

vector<long long> mult(mat &x, vector<long long> &v){
  vector<long long> u(N);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        u[i] = (u[i] + (x[i][j] * v[j]) % mod) % mod;
    }
  }
  return u;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    vector<long long> v(N);
    long long day;
    for(auto &i : v)cin >> i;
    cin >> day;
    mat x = { {1, 2, 0, 5, 1},
              {1, 0, 0, 0, 0},
              {0, 1, 0, 0, 0},
              {0, 0, 1, 0, 0},
              {0, 0, 0, 1, 0}};

    if(day > 4){
      x = binpow(x, day - 4);
      reverse(v.begin(), v.end());
      v = mult(x, v);
      cout << v[0] << endl;
    }
    else cout << v[day] << endl;

  }

  return 0;
}
