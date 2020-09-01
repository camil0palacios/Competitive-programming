#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 3100;
int n, m;
string s, t;
int dp[MXN][MXN];

int Dp(int i, int j) {
    if(i == n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(s[i] == t[j]) ans = Dp(i + 1, j + 1) + 1;
    else ans = max(ans, max(Dp(i + 1, j), Dp(i, j + 1)));
    return dp[i][j] = ans;
}

void rec(int i, int j, string & ans) {
    if(i == n || j == m) return;
    if(s[i] == t[j] && Dp(i, j) == Dp(i + 1, j + 1) + 1) {
        ans += s[i];
        rec(i + 1, j + 1, ans);
        return;
    } 
    else if(Dp(i, j) == Dp(i + 1, j)) {
        rec(i + 1, j, ans);
        return;
    } else {
        rec(i, j + 1, ans);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> t;
    n = s.size(), m = t.size();
    memset(dp, -1, sizeof dp);
    string ans;
    rec(0, 0, ans);
    cout << ans << endl;
    return 0;
}