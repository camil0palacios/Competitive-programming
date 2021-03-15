#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll p, q;
ll ans;

void fact(ll x) {
    ll t = p;
    while(t % q == 0) t /= x;
    ans = max(ans, t);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> p >> q;
        if(p % q != 0) { cout << p << endl; continue; }
        ans = 1;
        ll x = q;
        for(ll i = 2; i*i <= x; ++i) {
            if(x % i == 0) fact(i);
            while(x % i == 0) x /= i;
        }
        if(x > 1) fact(x);
        cout << ans << endl; 
    }
    return 0;
}