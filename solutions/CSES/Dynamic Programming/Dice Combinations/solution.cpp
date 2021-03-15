#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

void add(int & a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 1; j <= 6; j++) {
            if(i + j <= n) add(dp[i], dp[i + j]);
        }
    }
    cout << dp[0] << endl;
    return 0;
}