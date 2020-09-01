#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 205;
const int MXP = 4e4 + 4;
int n, a, b;
int h[MXN], s[MXN];
int dp[MXN][MXP][3];

int Dp(int i, int x, int lst) {
    if(i == n + 1) return 0;
    if(dp[i][x][lst] != -1) return dp[i][x][lst];
    int ans = INF;
    int y = s[i - 1] - x;
    if(h[i] <= a - x) ans = min(ans, Dp(i + 1, x + h[i], 0) + (lst ? min(h[i], h[i - 1]) : 0));
    if(h[i] <= b - y) ans = min(ans, Dp(i + 1, x, 1) + (!lst ? min(h[i], h[i - 1]) : 0));
    return dp[i][x][lst] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + h[i];
    }
    memset(dp, -1, sizeof dp);
    int ans = min(Dp(1, 0, 0), Dp(1, 0, 1)); 
    cout <<  (ans >= INF ? -1 : ans) << endl;
    return 0;
}