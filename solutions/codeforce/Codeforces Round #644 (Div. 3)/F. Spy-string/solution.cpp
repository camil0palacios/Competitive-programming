#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string a[11];
int n, m;
int dp[10][1 << 10];

int Dp(int idx, int msk) {
    if(idx == m) return 1;
    if(dp[idx][msk] != -1) return dp[idx][msk];
    bool ans = 0;
    for(int i = 0; i < 26; i++) {
        bool ok = 1;
        int tmp = msk;
        for(int j = 0; j < n; j++) {
            if(i != (a[j][idx] - 'a')) {
                if(!((tmp >> j) & 1)) tmp |= (1 << j);
                else ok = 0; 
            }
        }
        if(ok) ans |= Dp(idx + 1, tmp);
    }
    return dp[idx][msk] = ans;
}

void rec(int idx, int msk, string & ans) {
    if(idx == m) {
        return;
    }
    for(int i = 0; i < 26; i++) {
        bool ok = 1;
        int tmp = msk;
        for(int j = 0; j < n; j++) {
            if(i != (a[j][idx] - 'a')) {
                if(!((tmp >> j) & 1)) tmp |= (1 << j);
                else ok = 0; 
            }
        }
        if(ok && Dp(idx, msk) == Dp(idx + 1, tmp)) {
            ans += char(i + 'a');
            rec(idx + 1, tmp, ans);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof dp);
        bool ans = Dp(0, 0);
        if(ans) {
            string s;
            rec(0, 0, s);
            cout << s << endl;
        } else { 
            cout << -1 << endl;
        }
    }
    return 0;
}