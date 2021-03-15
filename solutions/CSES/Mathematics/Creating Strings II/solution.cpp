#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 1e6 + 5;
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fact[0] = inv[0] = 1;
    for(int i = 1; i < MXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = be(fact[i], mod - 2);
    }
    string s;
    cin >> s;
    int n = (int) s.size();
    int f[26];
    memset(f, 0, sizeof f);
    for(int i = 0; i < n; i++) {
        f[s[i]-'a']++;
    }
    ll ans = fact[n];
    for(int i = 0; i < 26; i++) {
        if(f[i]) ans = (ans * inv[f[i]]) % mod;
    }
    cout << ans << endl;
    return 0;
}