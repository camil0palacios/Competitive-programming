#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
int a, b;
int dp[505][505];

int go(int x, int y) {
    if(x == y) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    int ans = INF;
    for(int i = 1; i < x; i++) {
        ans = min(ans, go(i, y) + go(x - i, y) + 1);
    }
    for(int i = 1; i < y; i++) {
        ans = min(ans, go(x, i) + go(x, y - i) + 1);
    }
    return dp[x][y] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << go(a, b) << endl;
    return 0;
}