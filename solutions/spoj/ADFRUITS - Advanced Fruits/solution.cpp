#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string a, b;
int n, m;
int dp[110][110];

int Dp(int i, int j) {
    if(i == n && j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 220;
    if(i < n && j < m && a[i] == b[j]) ans = min(ans, Dp(i + 1, j + 1) + 1);
    if(i < n) ans = min(ans, Dp(i + 1, j) + 1);
    if(j < m) ans = min(ans, Dp(i, j + 1) + 1);
    return dp[i][j] = ans;
}

void build(int i, int j) {
    if(i == n && j == m) {
        cout << endl;
        return;
    }
    int st = dp[i][j];
    if(i < n && j < m && a[i] == b[j] && st == Dp(i + 1, j + 1) + 1) {
        cout << a[i];
        return build(i + 1, j + 1);
    } 
    if(i < n && st == Dp(i + 1, j) + 1) {
        cout << a[i];
        return build(i + 1, j);
    }
    if(j < m && st == Dp(i, j + 1) + 1){
        cout << b[j];
        return build(i, j + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> a >> b) {
        n = a.size(), m = b.size();
        memset(dp, -1, sizeof dp);
        Dp(0, 0);
        build(0, 0);
    }
    return 0;
}