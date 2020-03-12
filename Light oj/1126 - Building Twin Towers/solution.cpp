#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 55;
const int MAXH = 260000;
const int INF = 1e9;
int a[MAXN];
int dp[2][MAXH*2];

int Dp(int n, int mx) {
    int zero = MAXH;
    int cur = 0;
    for(int i = -zero; i <= zero; i++) {
        dp[cur][zero + i] = -INF;
    }
    dp[cur][zero] = 0;
    for(int i = n - 1; i >= 0; i--) {
        cur ^= 1;
        for(int j = -mx; j <= mx; j++) {
            int ans = -INF;
            if(j + a[i] <= mx)ans = max(ans, dp[cur^1][zero + j + a[i]] + a[i]);
            if(abs(j - a[i]) <= mx)ans = max(ans, dp[cur^1][zero + j - a[i]] + a[i]);
            ans = max(ans, dp[cur ^ 1][zero + j]);
            dp[cur][zero + j] = ans;
        }
    }
    return dp[cur][zero];
}

void sol() {
    int n, acc = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        acc += a[i];    
    }
    sort(a, a + n);
    int ans = Dp(n, (acc + 1) / 2);
    if(ans <= 0)cout << "impossible" << endl;
    else cout << ans / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol();
    }
    return 0;
}