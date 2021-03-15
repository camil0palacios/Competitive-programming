#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 5005;
int a[MXN], b[MXN];
int n, m;
int dp[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    int lst = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != lst) b[++m] = a[i];
        lst = a[i];
    }
    m++;
    for(int i = 0; i <= m; i++) {
        dp[0][i] = m - i;
        dp[i][m] = i;
    }
    for(int l = 1; l <= m; l++) {
        for(int r = m - 1; r > l; r--) {
            if(b[l] == b[r]) dp[l][r] = dp[l - 1][r + 1] + 1;
            else dp[l][r] = min(dp[l - 1][r], dp[l][r + 1]) + 1;
        }
    }
    int ans = INF;
    for(int i = 1; i < m; i++) {
        ans = min(ans, dp[i - 1][i + 1]);
    }
    cout << ans << endl; 
    return 0;
}