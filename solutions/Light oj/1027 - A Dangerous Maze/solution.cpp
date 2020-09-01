#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, sum = 0, ps = 0, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum += abs(x);
        ps += (x > 0);
    }
    if(ps){
        int g = __gcd(sum, ps);
        cout << sum / g << "/" << ps / g << endl;
    }else{
        cout << "inf" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}