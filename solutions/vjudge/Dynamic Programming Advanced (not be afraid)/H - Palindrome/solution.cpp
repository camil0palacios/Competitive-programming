#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

const int MXN = 5010;
int n; string s;

int main() {
    cin >> n >> s;
    int dp[2][n];
    for(int i = 0; i < n; i++) dp[0][i] = dp[1][i] = 0;
    for(int l = n - 2; l >= 0; l--) {
        for(int r = 0; r < n; r++) dp[1][r] = dp[0][r], dp[0][r] = 0;
        dp[0][l + 1] = s[l] == s[l + 1] ? 0 : 1;
        for(int r = l + 2; r < n; r++) {
            if(s[l] == s[r]) {
                dp[0][r] = dp[1][r - 1];
            } else {
                dp[0][r] = min(dp[0][r - 1], dp[1][r]) + 1;
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}