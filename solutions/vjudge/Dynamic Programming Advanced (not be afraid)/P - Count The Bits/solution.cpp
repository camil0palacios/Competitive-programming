#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1000000009;
int k, b;
ll dp[130][1001][130];

ll modpow(ll a, ll b, ll m) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll Dp(int idx, int res, int bits) {
    if(idx == b) return res == 0 ? bits : 0;
    if(dp[idx][res][bits] != -1) return dp[idx][res][bits];
    ll ans = 0;
    for(int i = 0; i <= 1; i++) {
        ans = (ans + Dp(idx + 1, i ? (modpow(2, b - 1 - idx, k) + res) % k : res, bits + i)) % mod;
    } 
    return dp[idx][res][bits] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> k >> b;
    memset(dp, -1, sizeof dp);
    cout << Dp(0, 0, 0) << endl;
    return 0;
}