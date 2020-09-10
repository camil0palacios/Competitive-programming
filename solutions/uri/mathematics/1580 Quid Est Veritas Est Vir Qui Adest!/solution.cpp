#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
const int MXN = 1010;
ll fact[MXN];

void calc() {
    fact[0] = 1;
    for(int i = 1; i < MXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll pow_mod(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1; 
    }
    return ans;
}

// n! / a! * b! * c! ...... z! 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    calc();
    string s;
    while(cin >> s) {
        int n = (int) s.size();
        int p[26];
        memset(p, 0, sizeof p);
        for(int i = 0; i < n; i++) {
            p[s[i] - 'A']++;
        }
        ll div = 1;
        for(int i = 0; i < 26; i++) {
            if(p[i]) div = (div * fact[p[i]]) % mod;  
        }
        ll ans = (fact[n] * pow_mod(div, mod - 2)) % mod;
        cout << ans << endl;
    }
    return 0;
}