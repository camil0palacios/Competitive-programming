#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int fib[40],call[40];
  fib[0] = 0;
  fib[1] = call[0] = call[1] = 1;
  for(int i = 2; i <  40; i++){
    fib[i] = fib[i-1] + fib[i-2];
    call[i] = call[i-1] + call[i-2] + 1;
  }
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    cout << "fib(" << x << ") = " << call[x] - 1 << " calls = " << fib[x] << endl;
  }
  return 0;
}
