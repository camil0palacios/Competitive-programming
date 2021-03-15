#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 5050;
int dp[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    string s;
    cin >> s >> q;
    int n = (int) s.size();
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if(i) dp[i-1][i] = s[i] == s[i-1];
    }
    for(int i = n - 3; i >= 0; i--) 
        for(int j = i + 2; j < n; j++) 
            if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
    for(int i = n - 2; i >= 0; i--) 
        for(int j = i + 1; j < n; j++) 
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
    for(int l, r; q--;) {
        cin >> l >> r;
        cout << dp[l-1][r-1] << endl;
    }
    return 0;
}