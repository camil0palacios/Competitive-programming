#include <bits/stdc++.h>
using namespace std;

int main(){
  int  d, sumTime;
  cin >> d >> sumTime;
  int mmin = 0, mmax = 0;
  vector<int> mini(d),maxi(d);
  for(int i = 0; i < d ; i++){
    cin >> mini[i] >> maxi[i];
    mmin += mini[i]; mmax += maxi[i];
  }
  if(mmax < sumTime || mmin > sumTime){
    cout << "NO" <<endl;
    return 0;
  }
  cout << "YES" << endl;
  vector<int> ans;
  for(int i = 0; i < d ; i++){
    mmin -= mini[i];
    if(mmin <= sumTime - maxi[i]){
      cout << maxi[i] ;
      sumTime -= maxi[i];
    }
    else{
      cout << sumTime - mmin;
      sumTime -= sumTime - mmin;
    }
    cout << (i < d - 1 ? ' ' : '\n');
  }
  return 0;
}
