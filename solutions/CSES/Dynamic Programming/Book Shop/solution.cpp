#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 1001;
const int MXM = 1e5 + 5;
int h[MXN], s[MXN];
int dp[2][MXM];

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
        cin >> h[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool cur = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= x; j++) {
            dp[cur][j] = dp[cur^1][j];
            if(h[i] <= j) dp[cur][j] = max(dp[cur][j], dp[cur^1][j - h[i]] + s[i]);
        }
        cur ^= 1;
    } 
    cur ^= 1;
    cout << dp[cur][x] << endl;
    return 0;
}