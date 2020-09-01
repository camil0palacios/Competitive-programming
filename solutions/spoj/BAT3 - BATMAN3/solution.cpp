#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
int a[1010];
int dp[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m; 
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp, 0, sizeof dp);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] > a[j] || i == m)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dp[i] + 1);
        }
        cout << ans << endl;
    }
    return 0;
}