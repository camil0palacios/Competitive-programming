#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    while(cin >> n >> k >> k){
        vector<int> v(n-1);
        int t, a ;
        cin >> a;
        for(int i = 0; i < n - 1; i++){
            cin >> t;
            v[i] = t-a-1;
            a = t;
        }
        sort(v.begin(), v.end());
        int ans = n;
        for(int i = 0; i < n - k; i++){
            ans += v[i];
        }
        cout << ans << endl;
    }
    return 0;
}