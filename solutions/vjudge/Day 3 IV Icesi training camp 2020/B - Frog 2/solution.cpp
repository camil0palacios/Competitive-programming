#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e5 + 5;
int n, k;
int h[MXN];
int dp[MXN];

int Dp(int idx) {
    if(idx == n - 1) return 0;
    if(dp[idx] != -1) return dp[idx];
    int ans = 1e9;
    for(int i = idx + 1; i <= min(n - 1, idx + k); i++) {
        ans = min(ans, Dp(i) + abs(h[idx] - h[i]));
    }
    return dp[idx] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    memset(dp, -1, sizeof dp);
    cout << Dp(0) << endl;
    return 0;
}