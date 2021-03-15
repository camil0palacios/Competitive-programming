#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int x[MXN], y[MXN], t[MXN];
int dp[MXN];
int mx[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int r, n;
    cin >> r >> n;
    x[0] = y[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        dp[i] = -1e9;
        for(int j = max(0, i - 2*r); j < i; j++) {
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }   
        if(i > 2*r) dp[i] = max(dp[i], mx[i - 2*r] + 1);
        mx[i] = max(dp[i], mx[i - 1]);
    }
    cout << mx[n] << endl;
    return 0;
}