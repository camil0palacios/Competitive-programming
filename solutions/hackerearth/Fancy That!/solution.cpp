#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string s;
ll dp[11][2][2];

ll go(int idx, int top, int st) {
    if(idx == s.size())return st;
    if(dp[idx][top][st] != -1)return dp[idx][top][st];
    ll ans = 0;
    int mx = (top ? s[idx] - '0' : 9), inc = (st ? 1 : 2);
    for(int i = 0; i <= mx; i += inc) {
        ans += go(idx + 1, top && i == mx, st | (i != 0));
    }
    return dp[idx][top][st] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll l, r;
        cin >> l >> r;
        s = to_string(l - 1);
        memset(dp, -1, sizeof dp);
        ll ans = go(0, 1, 0);
        s = to_string(r);
        memset(dp, -1, sizeof dp);
        cout << go(0, 1, 0) - ans << endl;
    }
    return 0;
}