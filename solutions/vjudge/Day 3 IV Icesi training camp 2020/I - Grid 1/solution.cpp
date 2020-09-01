#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
const int MXN = 3005;
char a[MXN][MXN];
ll dp[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp[n - 1][m - 1] = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(a[i][j] == '#') continue;
            if(i + 1 < n && a[i + 1][j] != '#') dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
            if(j + 1 < m && a[i][j + 1] != '#') dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}