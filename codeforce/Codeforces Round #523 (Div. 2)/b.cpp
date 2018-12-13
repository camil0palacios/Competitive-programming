#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    while(cin >> n >> m){
        vector<long long> v(n);
        long long mmax = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            mmax = max(mmax, v[i]);
        }
        sort(v.begin(), v.end());
        long long cur = 1, ans = 0;
        for(auto i : v){
            if(i >= cur)cur++;
            ans += i;
        }
        cur--;
        cout << ans - (n + mmax - cur) << endl;
    }
    return 0;
}