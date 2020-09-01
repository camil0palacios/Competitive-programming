#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m){
        vector<int> v(m);
        for(auto & i : v)cin >> i;
        sort(v.begin(), v.end());
        int ans = 1005, top = abs(m - n);
        for(int i = 0; i <= top; i++){
            ans = min(ans, v[n+i-1] - v[i]);
        }
        cout << ans << endl;
    }
    return 0;   
}