#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    while(cin >> n >> k){
        vector<int> v(n);
        for(auto & i : v)cin >> i;
        int ans = 0;
        for(int b = 0; b < k; b++){
            vector<int> used(n, 1);
            for(int i = 0; i*k + b - 1 < n; i++){
                used[i*k + b - 1] = 0;
            }
            int e = 0, s = 0;
            for(int i = 0; i < n; i++){
                if(used[i]){
                    if(v[i] == -1)s++;
                    if(v[i] == 1)e++;
                }
            }
            ans = max(ans, abs(e-s));
        }
        cout << ans << endl;
    }
    return 0;
}