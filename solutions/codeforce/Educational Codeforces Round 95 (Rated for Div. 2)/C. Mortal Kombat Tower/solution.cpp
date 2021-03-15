#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
 
const int INF = 1e9;
const int MXN = 2e5 + 5;
int a[MXN];
int dp[MXN][2];
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = INF;
        dp[n][0] = dp[n][1] = 0;
        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = min(dp[i + 1][1] + a[i], i + 1 < n ? dp[i + 2][1] + a[i] + a[i + 1] : INF);
            dp[i][1] = min(dp[i + 1][0], dp[min(n, i + 2)][0]);
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}