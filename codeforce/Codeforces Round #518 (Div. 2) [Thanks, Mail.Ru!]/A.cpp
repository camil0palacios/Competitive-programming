#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  unsigned long long N,M,K,L, ans;
  cin >> N >> M >> K >> L;
  L += K;
  if(M < L)
    ans = (L % M) ? L / M + 1 : L / M;
  else
    ans = 1;
  if(ans * M <= N)
    cout << ans << "\n";
  else
    cout << -1 << "\n";
  return 0;
}