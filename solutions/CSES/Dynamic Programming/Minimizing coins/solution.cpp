#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int INF = 1e9;
const int MXN = 105;
const int MXS = 1e6 + 5;
int n, x, c[MXN];
int dp[MXN][MXS];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= x; j++) dp[i][j] = INF;
    }
    dp[n][x] = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = x; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j];
            if(j + c[i] <= x)
                dp[i][j] = min(dp[i][j], dp[i][j + c[i]] + 1);
        }
    }
    cout << (dp[0][0] < INF ? dp[0][0] : -1) << endl;
    return 0;
}