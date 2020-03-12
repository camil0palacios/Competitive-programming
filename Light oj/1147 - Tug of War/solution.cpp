#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int w[105];
int ps[105];
bool dp[2][55][50005];

int Dp(int n, int sum) {
    ps[0] = w[0];
    for(int i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + w[i];
    }
    memset(dp, 0, sizeof dp);
    int shalf = (sum + 1) / 2, nhalf = (n + 1) / 2;
    bool cur = 0;
    dp[cur][0][0] = 1;
    for(int i = n - 1; i >= 0; i--) {
        cur ^= 1;
        int lf = min(nhalf, n - i);
        for(int j = 0; j <= nhalf; j++) {
            int mxs = min(shalf, ps[i]);
            for(int k = 0; k <= shalf; k++) {
                bool ans = dp[cur ^ 1][j][k];
                if(j && k >= w[i]) {
                    ans |= dp[cur ^ 1][j - 1][k - w[i]];
                }
                dp[cur][j][k] = ans;
            }
        }
    }
    int res1 = 0;
    for(int i = nhalf; i >= 0; i--) {
        for(int j = shalf; j >= 0; j--) {
            if(dp[cur][i][j]) {
                res1 = max(res1, j);
            }
        }
    }
    int res2 = sum - res1;
    cout << res1 << ' ' << res2 << endl;
}

void sol() {
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    sort(w, w + n);
    reverse(w, w + n);
    Dp(n, sum);
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