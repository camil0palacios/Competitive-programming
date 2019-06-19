#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n;
    cin >> n;
    ll l = ceil(sqrt((double)n));
    ll high = l*l;
    ll mid = high - l + 1;
    ll low = (high - l + 1) - l + 1;
    ll a = 1, b = 1; 
    if(l % 2 == 0){
        if(low <= n && n <= mid){
            b = l;
            a = l - (mid - n);
        }else{
            a = l;
            b = l - (n - mid);
        }
    }else{
        if(low <= n && n <= mid){
            a = l;
            b = l - (mid - n);
        }else{
            b = l;
            a = l - (n - mid);
        }
    }
    cout << a << " " << b << endl;
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