#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    while(cin >> n){
        long double dist = sqrt(n);
        int k = dist, ans;
        if(double(k) == dist)ans = k*2;
        else if(dist - double(k) < double(k + 1) - dist){
            ans = int(double(k + 0.5)*(double)2);
        }else{
            ans = (k + 1)*2;
        }
        cout << ans << endl;
    }
    return 0;
}