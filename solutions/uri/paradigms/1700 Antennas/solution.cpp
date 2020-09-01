#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int INF = (1 << 30);
const int MXN = 1010;
int n, a[MXN];
ll dp[2][50000 * 2 + 10];

// dp[i][val] = max(dp[i + 1][val], dp[i + 1][val + A[i]] + a[i], dp[i + 1][val - a[i]] + a[i])

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n && n) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sum /= 2;
        for(int val = -sum; val <= sum; val++) dp[0][sum + val] = -INF;
        dp[0][sum] = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int val = -sum; val <= sum; val++) 
                dp[1][sum + val] = dp[0][sum + val], dp[0][sum + val] = 0;
            for(int val = -sum; val <= sum; val++) {
                ll ans = dp[1][sum + val];
                if(val + a[i] <= sum) 
                    ans = max(ans, dp[1][sum + val + a[i]] + a[i]);
                if(val - a[i] >= -sum) 
                    ans = max(ans, dp[1][sum + val - a[i]] + a[i]);
                dp[0][sum + val] = ans;
            }
        }
        cout << (dp[0][sum] <= 0 ? 0 : dp[0][sum] / 2) << endl;
    }
    return 0;
}

/* 4
1 2 3 4
4
5 5 5 5
7
3 3 6 6 6 6 6
0 */
