#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int mmin = 0, mmax = 0, ans = 0, tmp;
        cin >> tmp;
        mmin = tmp, mmax = tmp;
        for(int i = 0; i < n - 1; i++){
            cin >> tmp;
            if(tmp > mmax)mmax = tmp, ans++;
            else if(tmp < mmin)mmin = tmp, ans++;
        }
        cout << ans << endl;
    }
    return 0;
}