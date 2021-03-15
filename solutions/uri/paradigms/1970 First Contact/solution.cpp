#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int Mxn = 101;
int n, k, x[Mxn];
int dp[Mxn][51][51][51];

int Dp(int i, int a, int b, int c) {
    if(i == n) return 0;
    int & ans = dp[i][a][b][c];
    if(ans != -1) return ans;
    ans = Dp(i + 1, a, b, c);
    if(x[i] <= a) ans = max(ans, Dp(i + 1, a - x[i], b, c) + x[i]);
    if(x[i] <= b) ans = max(ans, Dp(i + 1, a, b - x[i], c) + x[i]);
    if(x[i] <= c) ans = max(ans, Dp(i + 1, a, b, c - x[i]) + x[i]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> k) {
        for(int i = 0; i < n; i++) cin >> x[i];
        int cart[3] = {0, 0, 0};
        for(int i = 0; i < k; i++) cin >> cart[i];
        memset(dp, -1, sizeof dp);
        cout << Dp(0, cart[0], cart[1], cart[2]) << endl;
    }
    return 0;
}