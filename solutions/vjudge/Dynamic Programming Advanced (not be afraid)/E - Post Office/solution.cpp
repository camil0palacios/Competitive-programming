// #include <bits/stdc++.h>
#include <iostream>
#define endl '\n'
#define ll long long
using namespace std;

const ll inf = 1e18;
int n, p;
int a[310];
ll dp[310][32], dist[310][310];

void calDist() {
    for(int i = 2; i <= n; i++) {
        dist[0][i] = dist[0][i - 1] + (i - 1) * (a[i] - a[i - 1]); 
    }
    for(int i = n - 1; i; i--) {
        dist[i][n + 1] = dist[i + 1][n + 1] + (n - i) * (a[i + 1] - a[i]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = i + 1; k < j; k++) {
                dist[i][j] += min(a[k] - a[i], a[j] - a[k]);
            }
        }
    }
}

ll Dp(int i, int k) {
    if(k == 0) return dist[i][n + 1];
    if(dp[i][k] != -1) return dp[i][k];
    ll ans = inf;
    for(int j = i + 1; j <= n; j++) {
        ans = min(ans, Dp(j, k - 1) + dist[i][j]);
    }
    return dp[i][k] = ans;
}

void clearDp() {
    for(int i = 0; i < 310; i++) {
        for(int j = 0; j < 32; j++) {
            dp[i][j] = -1;
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> p;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    calDist();
    clearDp();
    ll ans = inf;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, Dp(i, p - 1) + dist[0][i]);
    }
    cout << ans << endl;
    return 0;
}