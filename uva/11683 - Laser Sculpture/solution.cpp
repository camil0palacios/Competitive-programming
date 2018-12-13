#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n){
        int bef, cur, ans = 0;
        cin >> bef;
        ans = n - bef;
        while(--m){
            cin >> cur;
            if(cur < bef){
                ans += bef - cur;
            }
            bef = cur;
        }
        cout << ans << endl;
    }
    return 0;
}