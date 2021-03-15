#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 101;
int n, m;
char a[MXN][MXN];
int dp[MXN][MXN][MXN];

// p = x1 + y1
// p = x2 + y2
// x1 + y1 = x2 + y2
// x1 + y1 - x2 = y2

int go(int x1, int y1, int x2) {
    if(x1 == n - 1 && y1 == m - 1) return a[x1][y1] == '*';
    if(dp[x1][y1][x2] != -1) return dp[x1][y1][x2];
    int ans = -INF;
    int y2 = x1 + y1 - x2;
    int v1 = a[x1][y1] == '*', v2 = a[x2][y2] == '*', v3 = (x1 == x2 && y1 == y2 && a[x1][y1] == '*');
    if(x1 + 1 <= n - 1 && a[x1 + 1][y1] != '#') {
        if(y2 + 1 <= m - 1 && a[x2][y2 + 1] != '#') ans = max(ans, go(x1 + 1, y1, x2));
        if(x2 + 1 <= n - 1 && a[x2 + 1][y2] != '#') ans = max(ans, go(x1 + 1, y1, x2 + 1));
    }
    if(y1 + 1 <= m - 1 && a[x1][y1 + 1] != '#') {
        if(y2 + 1 <= m - 1 && a[x2][y2 + 1] != '#') ans = max(ans, go(x1, y1 + 1, x2));
        if(x2 + 1 <= n - 1 && a[x2 + 1][y2] != '#') ans = max(ans, go(x1, y1 + 1, x2 + 1));
    } 
    ans += v1 + v2 - v3;
    return dp[x1][y1][x2] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                // for(int k = 0; k < n; k++) 
                //     dp[i][j][k] = -1;
            }
        }
        memset(dp, -1, sizeof dp);
        if(a[0][0] != '#') cout << go(0,0,0) << endl;
        else cout << 0 << endl;
    }
    return 0;
}