#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 101;
int coin[MXN];

void add(int & a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    int dp[n + 1][x + 1];
    memset(dp, 0, sizeof dp);
    dp[n][x] = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = x; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j];
            if(j + coin[i] <= x)
                add(dp[i][j], dp[i][j + coin[i]]); 
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}