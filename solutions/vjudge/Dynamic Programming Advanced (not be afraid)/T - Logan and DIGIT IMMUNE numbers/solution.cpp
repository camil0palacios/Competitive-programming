#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string l, r;
ll k, dp[19][2][2][1 << 6][3][9][7][9];
int dig[5] = {0, 3, 5, 7, 9};

bool check(int msk, int a, int b, int c, int d) {
    if(((msk >> 0) & 1) && !a) return 0;
    if(((msk >> 1) & 1) && !b) return 0;
    if(((msk >> 2) & 1) && !c) return 0;
    if(((msk >> 3) & 1) && !d) return 0;
    return 1;
}

ll Dp(string & s, int idx, bool top, bool z, int msk, int r3, int r5, int r7, int r9) {
    if(idx == s.size()) return check(msk, r3, r5, r7, r9);
    ll & ans = dp[idx][top][z][msk][r3][r5][r7][r9]; 
    if(ans != -1) return ans;
    int mx = (top ? s[idx] - '0' : 9);
    ans = 0;
    for(int i = 0; i < 5 && dig[i] <= mx; i++) {
        if(!z && dig[i] == 0) continue;
        ans += Dp(s, idx + 1, top && dig[i] == mx, z && dig[i] == 0, i ? msk | (1 << (i - 1)) : 0, 
            (r3*10 + dig[i]) % 3, (r5*10 + dig[i]) % 5, (r7*10 + dig[i]) % 7, (r9*10 + dig[i]) % 9);
    }
    return ans;
}

void rec(string & s, int idx, bool top, bool z, int msk, int r3, int r5, int r7, int r9) {
    if(idx == s.size()) { cout << endl; return; }
    int mx = (top ? s[idx] - '0' : 9);
    for(int i = 0; i < 5 && dig[i] <= mx; i++) {
        if(!z && dig[i] == 0) continue;
        ll state = Dp(s, idx + 1, top && dig[i] == mx, z && dig[i] == 0, i ? msk | (1 << (i - 1)) : 0, 
            (r3*10 + dig[i]) % 3, (r5*10 + dig[i]) % 5, (r7*10 + dig[i]) % 7, (r9*10 + dig[i]) % 9); 
        if(k > state) {
            k -= state;
        } else {
            if(dig[i] != 0)cout << dig[i];
            rec(s, idx + 1, top && dig[i] == mx, z && dig[i] == 0, i ? msk | (1 << (i - 1)) : 0,
                (r3*10 + dig[i]) % 3, (r5*10 + dig[i]) % 5, (r7*10 + dig[i]) % 7, (r9*10 + dig[i]) % 9);
            return;
        }
    }
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        cin >> l >> r >> k;
        string nl = to_string(stoll(l) - 1);
        memset(dp, -1, sizeof dp);
        ll x = Dp(nl, 0, 1, 1, 0, 0, 0, 0, 0);
        memset(dp, -1, sizeof dp);
        ll y = Dp(r, 0, 1, 1, 0, 0, 0, 0, 0);
        if(k <= y - x){ 
            k += x;
            rec(r, 0, 1, 1, 0, 0, 0, 0, 0);
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}