#include <bits/stdc++.h>
using namespace std;

int main(){

    long long k, b, n, t;
    while(cin >> k >> b >> n >> t){
        long long x = 0, res = b, i = 0;
        for(i = 1; i <= n; i++){
            long long p = pow(k,i);
            x = res + p;
            if(x > t)break;
            res += p*b;
        }
        cout << n-i+1 << endl;
    }
    return 0;
}