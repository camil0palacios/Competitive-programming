#include <bits/stdc++.h>
using namespace std;

int main(){

    int k;
    cin >> k;
    while(k--){
        int c, b, n, ans = 0;
        cin >> c >> b >> n;
        while(n > 0){
            ans += (n % b)*(n % b);
            n /= b;
        }
        cout << c << " " << ans << endl;
    }
    return 0;
}