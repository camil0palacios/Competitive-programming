#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 210;
const int INF = 1e9;
int n, a, b;
int f[MXN], ps[MXN];
int dp[MXN][MXN*MXN][2];

int go(int i, int k, bool lst) {
    if(i == n) return 0;
    if(dp[i][k][lst] != -1) return dp[i][k][lst];
    int ans = INF;
    if(k + f[i] <= a) {
        int x = go(i + 1, k + f[i], 1);
        if(i && !lst) x += min(f[i], f[i - 1]);
        ans = min(ans, x);
    } 
    if(ps[i] - k <= b) {
        int x = go(i + 1, k, 0);
        if(i && lst) x += min(f[i], f[i - 1]);
        ans = min(ans, x);
    }
    return dp[i][k][lst] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt","w", stdout);
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) {
        cin >> f[i];
        if(i) ps[i] = ps[i - 1] + f[i];
        else ps[0] = f[0];
    }
    memset(dp, -1, sizeof dp);
    int ans = go(0, 0, 0);
    cout << (ans < INF ? ans : -1) << endl;
    return 0;
}