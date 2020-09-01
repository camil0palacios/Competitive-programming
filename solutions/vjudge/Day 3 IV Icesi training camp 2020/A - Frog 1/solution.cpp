#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e5 + 5;
int n;
int h[MXN];
int dp[MXN];

int Dp(int idx) {
    if(idx == n - 1) return 0; // caso base
    if(dp[idx] != -1) return dp[idx]; // caso dp
    int ans = Dp(idx + 1) + abs(h[idx] - h[idx + 1]);
    if(idx + 2 < n) ans = min(ans, Dp(idx + 2) + abs(h[idx] - h[idx + 2])); 
    return dp[idx] = ans; // guardar
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    // memset(dp, -1, sizeof dp);
    // cout << Dp(0) << endl;
    for(int i = n - 2; i >= 0; i--) {
        dp[i] = dp[i + 1] + abs(h[i] - h[i + 1]);
        if(i + 2 < n) dp[i] = min(dp[i], dp[i + 2] + abs(h[i] - h[i + 2]));
    }
    cout << dp[0] << endl;
    return 0;
}