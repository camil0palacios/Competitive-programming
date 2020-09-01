#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 2005;
int n, h, l, r;
int a[MAXN];
int dp[MAXN][MAXN];

int go(int i, int nh) {
    if(i == n)return l <= nh && nh <= r;
    if(dp[i][nh] != -1)return dp[i][nh];
    int rs = (l <= nh && nh <= r) && i != 0;
    int ans = max(go(i + 1, (nh + a[i] + h) % h), go(i + 1, (nh + a[i] - 1 + h) % h)) + rs;
    return dp[i][nh] = ans;
}

int main() {
    cin >> n >> h >> l >> r;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, 0) << endl;
    return 0;
}