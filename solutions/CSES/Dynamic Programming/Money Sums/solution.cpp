#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
int a[101];
const int MXS = 100 * 1000 + 5;
int dp[101][MXS];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= MXS; j++) {
            dp[i][j] = dp[i - 1][j];
            if(a[i] <= j) dp[i][j] |= dp[i - 1][j - a[i]];
        }
    }
    vector<int> ans;
    for(int i = 1; i <= sum; i++) {
        if(dp[n][i]) ans.emplace_back(i);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}