#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int Mxn = 2e5 + 5;
int a[Mxn];
int dp[Mxn][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, c;
    while(cin >> n >> c) {
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] - a[i]);
            if(i) dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] + a[i] - c);
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}