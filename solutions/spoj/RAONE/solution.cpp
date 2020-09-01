#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string s;
ll dp[18][2][100][100];

ll dptop(int idx, bool top, int even, int odd) {
    if(idx == s.size()) return even - odd == 1;
    ll & ans = dp[idx][top][even][odd];
    if(ans != -1) return ans;
    ans = 0;
    int mx = top ? s[idx] - '0' : 9;
    for(int i = 0; i <= mx; i++) {
        int j = s.size() - idx;
        int tmpe = j & 1 ? even : even + i;
        int tmpo = j & 1 ? odd + i : odd;
        ans += dptop(idx + 1, top && i == mx, tmpe, tmpo);
    }
    return ans;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    s = to_string(a - 1);
    memset(dp, -1, sizeof dp);
    ll left = dptop(0, 1, 0, 0);
    s = to_string(b);
    memset(dp, -1, sizeof dp);
    cout << dptop(0, 1, 0, 0) - left << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 0; cs < t; cs++) {
        solve();
    }
    return 0;
}