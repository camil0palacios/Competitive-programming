#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  if(m == 0){cout << n << " " << n << endl; return 0;}
  long long mmin = 2*m;
  if(mmin > n)cout << 0 << " ";
  else cout << n - mmin << " ";
  long long mmax = ceil((1 + sqrt(1LL + (8*m)))/2);
  if(mmax > n)cout << 0 << endl;
  else cout << n - mmax << endl;
  return 0;
}
