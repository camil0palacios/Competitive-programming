#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 1001;
char a[MXN][MXN];

void add(int & a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    dp[n - 1][n - 1] = (a[0][0] != '*' ? 1 : 0);
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == n - 1 && j == n - 1 || a[i][j] == '*') continue;
            if(i + 1 <= n - 1 && a[i + 1][j] != '*') add(dp[i][j], dp[i + 1][j]);
            if(j + 1 <= n - 1 && a[i][j + 1] != '*') add(dp[i][j], dp[i][j + 1]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}