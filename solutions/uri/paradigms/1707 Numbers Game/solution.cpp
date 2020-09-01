#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string s;
ll dp[10][2][9][81];

ll dptop(int idx, bool top, int res, int sum) {
    if(idx == s.size()) return res == 0 ? 0 : sum;
    ll & ans = dp[idx][top][res][sum]; 
    if(ans != -1) return ans;
    int mx = (top ? s[idx] - '0' : 9);
    ans = 0;
    for(int i = 0; i <= mx; i++) {
        ans += dptop(idx + 1, top && i == mx, (res*10 + i) % 2, sum + i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, r;
    while(cin >> l >> r) {
        if(l > r) swap(l, r);
        s = to_string(l - 1);
        memset(dp, -1, sizeof dp);
        ll ans = dptop(0, 1, 0, 0);
        s = to_string(r);
        memset(dp, -1, sizeof dp);
        cout << dptop(0, 1, 0, 0) - ans << endl;
    }
    return 0;
}