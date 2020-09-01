#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string a, b = "KEK";
int dp[2010][10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> a;
        memset(dp, 0, sizeof dp);
        dp[a.size()][b.size()] = 1;
        for(int i = a.size() - 1; i >= 0; i--) {
            for(int j = b.size(); j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];
                if(a[i] == b[j]) dp[i][j] += dp[i + 1][j + 1];
            }
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}