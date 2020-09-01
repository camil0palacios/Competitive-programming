#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1000010;
const ll MOD = 100000007;
ll powers[203800], it;
ll catalan[MXN];
ll fact[2*MXN + 5];

void precalc() {
    it = 0;
    for(ll i = 2; i <= 100001; i++) {
        ll num = i * i;
        while(num <= 10000000001LL) {
            powers[it++] = num;
            num *= i;
        }
    }
    sort(powers, powers + it);
    it = unique(powers, powers + it) - powers;
    powers[it++] = 10001000000LL;
}

ll powmod(ll a, ll b = MOD - 2) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

ll calcatalan() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i < 2*MXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    catalan[0] = catalan[1] = 1;
    for(int i = 2; i < MXN; i++) {
        catalan[i] = fact[2 * i];
        ll div = (fact[i] * fact[i + 1]) % MOD;
        div = powmod(div);
        catalan[i] = (catalan[i] * div) % MOD;
    }
}

void sol() {
    ll a, b;
    cin >> a >> b;
    int l = lower_bound(powers, powers + it, a) - powers;
    int r = lower_bound(powers, powers + it, b) - powers;
    if(powers[r] > b)r--;
    int x = r - l + 1;
    if(!x)cout << 0 << endl;
    else cout << catalan[x] << endl;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    precalc();
    calcatalan();
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol();
    }
    return 0;
}