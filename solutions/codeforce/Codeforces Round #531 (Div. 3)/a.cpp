#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    while(cin >> n){
        if((long long)(ceil(n/2.0)) % 2 == 0)cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}