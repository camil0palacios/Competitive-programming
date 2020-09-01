#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int inf = 100010;

int n, m, k;
int a[101][101];
string pat[101];
int dp[101][101], sum[101][101];

bool check(int x, int y) {
    for(int i = 0; i < m; i++) {
        int c = pat[x][i], d = pat[y][i];
        if((c == '+' || c == '-') && c == d) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> m && (n || m)){
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> pat[i];
        }
        memset(sum, 0, sizeof sum);
        for(int i = 0; i < n; i++) {
            for(int p = 0; p < k; p++) {
                for(int j = 0; j < m; j++) {
                    int x = pat[p][j];
                    if(x == '+') sum[i][p] += a[i][j];
                    if(x == '-') sum[i][p] -= a[i][j];
                }
            }
        }
        memset(dp, 0, sizeof dp);
        for(int i = n - 1; i > 0; i--) {
            for(int lst = 0; lst < k; lst++) {
                int ans = -inf;
                for(int nxt = 0; nxt < k; nxt++) {
                    if(check(lst, nxt)) {
                        ans = max(ans, dp[i + 1][nxt] + sum[i][nxt]);
                    }
                }
                dp[i][lst] = ans;
            }
        }
        int ans = -inf;
        for(int i = 0; i < k; i++) {
            ans = max(ans, dp[1][i] + sum[0][i]);
        }
        cout << ans << endl;
    }
    return 0;
}