#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
int n, a[MXN];
ll dp[MXN][3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i <= n + 2; i++) {
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
        }
        for(int i = n - 1; i >= 0; --i) {
            bool ok = i % 2 == 0;
            dp[i][0] = max(dp[i + 1][0] + (ok ? a[i] : 0), dp[i + 1][1]);
            dp[i][1] = max(dp[i + 2][1], dp[i + 1][2]) + (ok ? a[i - 1] : a[i]);
            dp[i][2] = dp[i + 1][2] + (ok ? a[i] : 0);
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}