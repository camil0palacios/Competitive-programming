#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e5 + 5;
int n, k;
int m[MXN][3];
int dp[MXN][4];

int x[3] = {0, 1, 2};

int Dp(int d, int lst) {
    if(d == n) return 0;
    if(dp[d][lst] != -1) return dp[d][lst];
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        if(lst != x[i]) {
            ans = max(ans, Dp(d + 1, i) + m[d][i]);
        }
    }
    return dp[d][lst] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m[i][0] >> m[i][1] >> m[i][2];
    }
    memset(dp, -1, sizeof dp);
    cout << Dp(0, 3) << endl;
    return 0;
}