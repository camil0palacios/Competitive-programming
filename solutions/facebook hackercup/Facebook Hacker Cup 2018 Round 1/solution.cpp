#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1010;
const ll mod = 1e9 + 7;
int n;
char a[3][MXN];
ll dp[3][MXN][3];

ll Dp(int x, int y, int d) {
    if(x == 2 && y == n - 1) return d == 2;
    if(dp[x][y][d] != -1) return dp[x][y][d];
    ll ans = 0;
    if(d == 0) {
        if(x - 1 >= 0 && a[x - 1][y] != '#') ans = (ans + Dp(x - 1, y, 1)) % mod;
        if(x + 1 < 3 && a[x + 1][y] != '#') ans = (ans + Dp(x + 1, y, 2)) % mod;
    } else if(y + 1 < n && a[x][y + 1] != '#') {
        ans = (ans + Dp(x, y + 1, 0)) % mod;
    }
    return dp[x][y][d] = ans;
}

void solve() {
    cin >> n;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
        }
    }
    int ans = 0;
    if(a[0][0] != '#') ans = Dp(0, 0, 0);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        solve(); 
    }
    return 0;
}