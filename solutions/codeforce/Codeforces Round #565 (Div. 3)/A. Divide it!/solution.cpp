#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    long long n;
    cin >> q;
    while(q--){
        cin >> n;
        int ans = 0, aux = -1;
        while(n > 1 && ans != aux){
            aux = ans;
            if(n % 2 == 0){
                n /= 2;
                ans++;
            }
            else if(n % 3 == 0){
                n = (2*n)/3;
                ans++;
            }
            else if(n % 5 == 0){
                n = (4*n)/5;
                ans++;
            }
        }
        if(n != 1)cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}