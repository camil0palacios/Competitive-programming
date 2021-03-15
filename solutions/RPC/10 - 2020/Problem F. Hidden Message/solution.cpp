#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
string a, b, c, t;
int n;
int dp[301][101][101];

void add(int & x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
}

int go(int i, int j, int k) {
    if(i == n) return 1;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ans = 0, m = i - j - k;
    if(a[j] == t[i]) add(ans, go(i + 1, j + 1, k));
    if(b[k] == t[i]) add(ans, go(i + 1, j, k + 1));
    if(c[m] == t[i]) add(ans, go(i + 1, j, k));
    return dp[i][j][k] = ans;
}

int main() {
    cin >> a >> b >> c >> t;
    n = t.size();
    memset(dp, -1, sizeof dp);
    cout << go(0, 0, 0) << endl;
    return 0;
}