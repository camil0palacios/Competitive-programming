#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n/2];
    for(int i = 0; i < (n/2); i++){
        cin >> p[i];
    }
    sort(p, p + (n/2));
    int mmin = 1e9;
    int cur = 1, ans = 0;
    for(int i = 0; i < (n/2); i++, cur += 2){
        ans += abs(p[i] - cur);
    }
    mmin = min(mmin, ans);
    ans = 0, cur = 2;
    for(int i = 0; i < (n/2); i++, cur += 2){
        ans += abs(p[i] - cur);
    }
    mmin = min(mmin, ans);
    cout << mmin << endl;
    return 0;
}