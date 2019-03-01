#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, v;
    while(cin >> n >> v){
        int ans = (v < n ? v : n - 1), cur = v - 1;
        bool f = (v < n ? 0 : 1);
        for(int i = 2; i <= n; i++){
            if(cur == n - i - 1 && !f){
                ans += i;
                f = 1;
            }
            else if(cur < n - i - 1 && !f){
                ans += (v - cur)*i;
                cur = v;
            }
            if(!f)cur--;
        }   
        cout << ans << endl;
    }
    return 0;
}