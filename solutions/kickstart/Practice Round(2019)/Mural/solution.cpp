#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, c = 1;
    cin >> t;
    while(t--){
        cin >> n;
        string v;
        cin >> v;
        int len = n/2 + (n&1), ans = 0;
        for(int i = 0; i < len; i++){
            ans += v[i] - '0';
        }
        int mmax = ans;
        for(int i = len; i < n; i++){
            ans -= v[i-len] - '0';
            ans += v[i] - '0';
            mmax = max(mmax, ans);   
        }
        cout << "Case #" << c++ << ": " << mmax << endl;
    }   
    return 0;
}