#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x; ll n;
    cin >> x >> n;
    set<ll> div;
    for(ll i = 2; i*i <= x; i++) {
        while(x % i == 0) {
            div.insert(i);
            x /= i;
        }
    }
    if(x > 1) div.insert(x);
    ll ans = 1;
    for(auto & d: div){
        ll t = 1;
        while(t <= n / d) {
            t *= d;
            ans = (ans * be(d, n / t)) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}