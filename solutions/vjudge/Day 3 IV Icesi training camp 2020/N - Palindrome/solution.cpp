#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 5005;
int n;
string s;
int dp[2][MXN];

int main() {
    cin >> n >> s;
    for(int l = n - 1; l >= 0; l--) {
        for(int i = 0; i < n; i++) dp[1][i] = dp[0][i], dp[0][i] = INF;
        dp[0][l] = 0;
        for(int r = l + 1; r < n; r++) {
            if(l == r - 1) dp[0][r] = s[l] != s[r] ? min(dp[1][r], dp[0][r - 1]) + 1 : 0;
            else {
                if(s[l] == s[r]) dp[0][r] = dp[1][r - 1];
                dp[0][r] = min(dp[0][r], min(dp[1][r], dp[0][r - 1]) + 1); 
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}