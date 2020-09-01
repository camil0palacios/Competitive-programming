#include <bits/stdc++.h>
#define endl '\n'
#define ull long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ull n;
    cin >> n;
    ull aprox = 1; 
    for(ull i = n; i >= 10; i /= 10) {
        aprox *= 10;
    }
    ull ans = 0, dif = 2e18;
    for(int i = 1; i <= 9; i++) {
        if(abs(aprox * i - n) <= dif){
            ans = aprox * i;
            dif = abs(aprox * i - n);
        } 
        if(aprox * i > n)break;
    }
    cout << ans << endl;
    return 0;
}