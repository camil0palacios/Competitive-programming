#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n, k;
    while(cin >> n >> k){
        long long mid = (n & 1 ? n/2 + 1: n/2);
        if(k <= mid){
            cout << k + (k-1) << endl;
        }else if(n & 1){
            cout << k - (n - k + 1) << endl;
        }else cout << k - (n - k) << endl;
    }
    return 0;
}