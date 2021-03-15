#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, p;
    cin >> n >> x >> p;
    int l = 0, r = n;
    ll ans = 1, less = x-1, big = n - x;
    while(l < r) {
        int m = (l + r) >> 1;
        if(m <= p) {
            l = m + 1;
            if(m < p) ans = (ans * less) % mod, less--;
        } else {
            r = m;
            ans = (ans * big) % mod, big--;
        }
    }
    for(int i = 1; i <= less + big; i++) ans = (ans * i) % mod;
    cout << ans<< endl;
    return 0; 
}