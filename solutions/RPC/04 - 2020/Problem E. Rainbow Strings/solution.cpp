#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 11092019;
ll cnt[26];
ll dp[26];

ll Dp(int i) {
    if(i == 26) return 1;
    if(dp[i] != -1) return dp[i];
    ll ans = (Dp(i + 1) + Dp(i + 1) * cnt[i]) % mod;
    return dp[i] = ans;
}

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    memset(dp, -1, sizeof dp);
    cout << Dp(0) << endl;
    return 0;
}