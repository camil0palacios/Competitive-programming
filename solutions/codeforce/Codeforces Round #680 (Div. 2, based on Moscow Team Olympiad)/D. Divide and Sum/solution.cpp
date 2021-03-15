#include <bits/stdc++.h>
#define endl '\n'
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ll long long
using namespace std;

const int mod = 998244353;
const int MXN = 2*150005;
ll a[MXN];
ll fact[MXN], inv[MXN];

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll nCr(ll n, ll r) {
    return (fact[n] * be(fact[r], mod - 2) % mod * be(fact[n-r], mod - 2)) % mod;
}

void cal() {
    fact[0] = inv[0] = 1;
    fori(i, 1, MXN) {
        fact[i] = (fact[i-1] * i) % mod;
        inv[i] = be(fact[i], mod - 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int n;
    cin >> n;
    fori(i, 0, 2*n) cin >> a[i];
    sort(a, a + 2*n);
    ll cost = 0;
    fori(i, 0, n) cost += a[2*n - i - 1] - a[i];
    cost %= mod;
    ll ans = (cost*nCr(2*n, n)) % mod;
    cout << ans << endl;
    return 0;
}