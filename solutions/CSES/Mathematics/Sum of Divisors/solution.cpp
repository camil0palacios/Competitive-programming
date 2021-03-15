#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }   
    return ans;
}

ll sum(ll n) {
    return n % mod * ((n - 1) % mod) % mod * ((mod + 1)/2) % mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ll k = n/(n/i);
        ans += n / i % mod * (sum(k + 1) - sum(i) + mod) % mod;
        i = k;
    }
    cout << ans % mod << endl;
    return 0;
}