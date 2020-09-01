#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, a[210];
int dp[210][210][210];

int Dp(int idx, int b, int w) {
    if(idx == n) return 0;
    if(dp[idx][b][w] != -1) return dp[idx][b][w];
    int ans = Dp(idx + 1, b, w);
    if(a[b] < a[idx]) ans = max(ans, Dp(idx + 1, idx, w) + 1);
    if(a[w] > a[idx]) ans = max(ans, Dp(idx + 1, b, idx) + 1);
    return dp[idx][b][w] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a[n] = 0; a[n + 1] = 1e6 + 1;
        memset(dp, -1, sizeof dp);
        cout << Dp(0, n, n + 1) << endl;
    }
    return 0;
}