#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#define endl '\n'
using namespace std;

struct worker { int l, p, s; };
const int MXM = 105;
const int MXN = 16005;
int dp[MXM][MXN];
int q[MXN];
worker a[MXM];

// dp[i][j] = max(dp[i + 1][k] + (j - k) * p[i]); s[i] - l < j < s[i] + l && j - k <= l
// dp[i][j] = max(dp[i + 1][k] - k * p[i]) + j * p[i];
// dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])

bool cmp(worker x, worker y) {
    return x.s < y.s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].l >> a[i].p >> a[i].s;
    }
    sort(a + 1, a + m + 1, cmp);    
    for(int i = 1; i <= m; i++) {
        int l = 1, r = 0;
        for(int k = max(0, a[i].s - a[i].l); k <= a[i].s - 1; k++) {
            while(l <= r && dp[i - 1][q[r]] - a[i].p*q[r] < dp[i - 1][k] - a[i].p*k) r--;
            q[++r] = k;
        }
        for(int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(j >= a[i].s) {
                while(l <= r && q[l] < j - a[i].l) l++;
                if(l <= r) dp[i][j] = max(dp[i][j], dp[i - 1][q[l]] - a[i].p*q[l] + a[i].p*j); 
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}