#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 5005;
int n, m;
string s, t;
int dp[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> t;
    n = s.size(), m = t.size();
    for(int i = n; i >= 0; i--) {
        for(int j = m; j >= 0; j--) {
            int ans = INF;
            if(i == n || j == m) ans = n - i + m - j;
            else {
                if(s[i] == t[j]) ans = dp[i + 1][j + 1];
                ans = min(ans, min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]}) + 1);
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}