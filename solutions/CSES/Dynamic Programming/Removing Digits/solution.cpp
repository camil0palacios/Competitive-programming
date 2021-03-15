#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
int dp[1000001];

int go(int n) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = INF;
    int tmp = n;
    while(tmp) {
        int dig = tmp % 10;
        if(dig <= n && dig != 0) ans = min(ans, go(n - dig) + 1);
        tmp /= 10;
    }
    return dp[n] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << go(n) << endl;
    return 0;
}