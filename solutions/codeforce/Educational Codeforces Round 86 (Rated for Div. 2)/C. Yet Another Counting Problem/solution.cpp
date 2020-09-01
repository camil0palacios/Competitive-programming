#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
 
ll a, b, q, lc;
 
ll calc(ll x) {
    ll dif = lc - b;
    ll c = x / lc;
    ll ans = c * dif; 
    if(c * lc + b <= x) ans += x - (c * lc + b - 1);
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b >> q;
        if(a > b) swap(a, b);
        lc = a * b / __gcd(a, b);
        while(q--) {
            ll l, r;
            cin >> l >> r;
            ll x = calc(l - 1), y = calc(r);
            cout <<  y - x << ' ';
        }
        cout << endl;
    }
    return 0;
}