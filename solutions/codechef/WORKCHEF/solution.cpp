#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 2520;
string s;
int k;
ll dp[20][2][1 << 9][mod];

bool check(int msk, int res) {
    int cnt = 0;
    for(int i = 1; i < 10; i++) {
        if(msk & (1 << (i - 1)) && res % i == 0)
            cnt++; 
    }
    return cnt >= k;
}

ll dptop(int idx, bool top, int msk, int res) {
    if(idx == s.size()) return check(msk, res);
    ll & ans = dp[idx][top][msk][res];
    if(ans != -1) return ans;
    ans = 0;
    int mx = top ? s[idx] - '0' : 9;
    for(int i = 0; i <= mx; i++) {
        int nmsk = msk;
        if(i != 0) nmsk |= 1 << (i - 1);
        ans += dptop(idx + 1, top && i == mx, nmsk, (res * 10 + i) % mod);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b >> k;
        s = to_string(a - 1);
        memset(dp, -1, sizeof dp);
        ll ans = dptop(0, 1, 0, 0);
        s = to_string(b);
        memset(dp, -1, sizeof dp);
        cout << dptop(0, 1, 0, 0) - ans << endl;
    }
    return 0;
}