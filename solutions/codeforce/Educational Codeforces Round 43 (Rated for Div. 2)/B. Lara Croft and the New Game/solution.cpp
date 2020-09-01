#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    long long x = 1, y = 1;
    if(k < n){
        x += k;
    }else{
        k -= n;
        x = n - k/(m-1);
        if(x & 1){
            y = m - k % (m-1);
        }else{
            y = k % (m-1) + 2;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}