#include <bits/stdc++.h>
using namespace std;

int main(){

    int k;
    while(cin >> k){
        int a[12], ans = 0;
        for(int i = 0; i < 12; i++)cin >> a[i];
        sort(a, a+12);
        if(k){
            for(int i = 11; i >= 0; i--){
                k -= a[i];
                ans++;
                if(k <= 0)break;
            }
        }
        if(k <= 0)cout << ans << endl;
        else cout << -1 << endl;
    }
}