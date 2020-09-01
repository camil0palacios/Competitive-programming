#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q, n, a, b;
    cin >> q;
    while(q--){
        cin >> n >> a >> b;
        long long mod = 0, res = 0;
        if((n*a) > ((n/2)*b+(n%2)*a)){
            cout << ((n/2)*b+(n%2)*a) << endl;
        }else {
            cout << n*a << endl;
        }
    }
    return 0;
}