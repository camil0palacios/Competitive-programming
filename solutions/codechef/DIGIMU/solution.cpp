#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string s;
int num[5] = {0, 3, 5, 7, 9};
ll dp[19][2][2][1 << 5][3][5][7][9];

bool check(int msk, int a, int b, int c, int d) {
    if(((msk >> 1) & 1) && !a) return 0;
    if(((msk >> 2) & 1) && !b) return 0;
    if(((msk >> 3) & 1) && !c) return 0;
    if(((msk >> 4) & 1) && !d) return 0;
    return 1;
}

ll dptop(int idx, bool top, bool z, int msk, int a, int b, int c, int d) {
    if(idx == s.size()) return check(msk, a, b, c, d);
    ll & ans = dp[idx][top][z][msk][a][b][c][d];
    if(ans != -1) return ans;
    ans = 0;
    int mx = top ? s[idx] - '0' : 9;
    for(int i = 0; i < 5 && num[i] <= mx; i++) {
        if(z && num[i] == 0) continue;
        ans += dptop(idx + 1, top && num[i] == mx, z || (num[i] > 0), msk | (1 << i),
            (a * 10 + num[i]) % 3, (b * 10 + num[i]) % 5, 
            (c * 10 + num[i]) % 7, (d * 10 + num[i]) % 9);
    }
    return ans;
}

void findk(int idx, bool top, bool z, int msk, int a, int b, int c, int d, ll k) {
    if(idx == s.size()) { cout << endl; return; }
    int mx = top ? s[idx] - '0' : 9;
    for(int i = 0; i < 5 && num[i] <= mx; i++) {
        if(z && num[i] == 0) continue;
        ll tmp = dptop(idx + 1, top && num[i] == mx, z || (num[i] > 0), msk | (1 << i),
            (a * 10 + num[i]) % 3, (b * 10 + num[i]) % 5, 
            (c * 10 + num[i]) % 7, (d * 10 + num[i]) % 9);
        if(k > tmp) k -= tmp;
        else {
            if(num[i] != 0) cout << num[i];
            findk(idx + 1, top && num[i] == mx, z || (num[i] > 0), msk | (1 << i),
                (a * 10 + num[i]) % 3, (b * 10 + num[i]) % 5, 
                (c * 10 + num[i]) % 7, (d * 10 + num[i]) % 9, k);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        ll a, b, k;
        cin >> a >> b >> k;
        s = to_string(a - 1);
        memset(dp, -1, sizeof dp);
        ll x = dptop(0, 1, 0, 0, 0, 0, 0, 0);
        s = to_string(b);
        memset(dp, -1, sizeof dp);
        ll y = dptop(0, 1, 0, 0, 0, 0, 0, 0);
        if(k <= y - x) {
            k += x;
            findk(0, 1, 0, 0, 0, 0, 0, 0, k);
        } else {
            cout << -1 << endl;
        } 
    }
    return 0;
}