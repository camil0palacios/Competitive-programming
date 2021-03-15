#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
const int MXN = 1e5 + 5;
ll suff[MXN], suff_sum[MXN], sum_p10[MXN];
ll pref[MXN], pref_sum[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = (int)s.size();
    ll p10 = 1;
    sum_p10[0] = 0;
    for(int i = 1; i < n; i++) {
        p10 = (p10 * 10) % mod;
        sum_p10[i] = (sum_p10[i - 1] + p10) % mod;
    }
    
    pref[0] = s[0] - '0', suff[n - 1] = s[n - 1] - '0';
    pref_sum[0] = pref[0], suff_sum[n - 1] = suff[n - 1];
    
    for(int i = 1; i < n; i++) {
        pref[i] = ((pref[i - 1]*10) % mod + (s[i] - '0')) % mod;
        pref_sum[i] = (pref[i] + pref_sum[i - 1]) % mod;
    }

    p10 = 10;
    for(int i = n - 2; i >= 0; i--) {
        suff[i] = (suff[i + 1] + ((s[i] - '0') * p10) % mod) % mod;
        suff_sum[i] = (suff[i] + suff_sum[i + 1]) % mod;
        p10 = (p10 * 10) % mod;
    }    
    
    ll ans = (pref_sum[n - 2] + suff_sum[1]) % mod;
    for(int i = 1; i < n - 1; i++) {
        ll tmp = (pref[i - 1] * sum_p10[n - i - 1]) % mod;
        tmp = (tmp + suff_sum[i + 1]) % mod;
        ans = (ans + tmp) % mod;
    }
    cout << ans << endl;
    return 0;
}