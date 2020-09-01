#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string l, r;
ll dp[20][2][2][59049];
ll pot3[10];

ll Dp(string & s, int idx, bool top, bool z, int msk) {
    if(idx == s.size())return 1;
    ll & ans = dp[idx][top][z][msk]; 
    if(ans != -1) return ans;
    int mx = (top ? s[idx] - '0' : 9);
    ans = 0;
    for(int i = 0; i <= mx; i++) {
        int cnt = (msk / pot3[i]) % 3;
        if(cnt < 2) {
            int nmsk = msk;
            if(z || i > 0) {
                nmsk += pot3[i];
            }
            ans += Dp(s, idx + 1, top && i == mx, z || i > 0, nmsk);
        }
    }
    return ans;
}

void precalc() {
    pot3[0] = 1;
    for(int i = 1; i < 10; i++) {
        pot3[i] = pot3[i - 1] * 3;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("exchange.in", "r", stdin);
    freopen("exchange.out", "w", stdout);
    cin >> l >> r;
    precalc();
    l = to_string(stoll(l) - 1);
    memset(dp, -1, sizeof dp);
    ll x = Dp(l, 0, 1, 0, 0);
    memset(dp, -1, sizeof dp);
    ll y = Dp(r, 0, 1, 0, 0);
    cout << y - x << endl;
    return 0;
}