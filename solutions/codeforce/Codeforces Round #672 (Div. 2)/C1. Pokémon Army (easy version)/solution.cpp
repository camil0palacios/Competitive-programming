#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 3e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll dp[n + 1][2];
        memset(dp, 0, sizeof dp);
        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] + a[i]);
            dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] - a[i]);
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}