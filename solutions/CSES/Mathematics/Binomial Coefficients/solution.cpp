#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
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

void cal() {
    fact[0] = inv[0] = 1;
    for(int i = 1; i < MXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = be(fact[i], mod - 2);
    }
}

ll nCr(int a, int b) {
    return (fact[a] * inv[b] % mod * inv[a - b]) % mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << nCr(a, b) << endl;
    }
    return 0;
}