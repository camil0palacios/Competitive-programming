#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 1e5 + 5;
const int MXM = 105;
int n, m;
int a[MXN];
int dp[MXN][MXM];

void add(int & a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int go(int idx, int lst) {
    if(idx == n) return 1;
    if(dp[idx][lst] != -1) return dp[idx][lst];
    int ans = 0;
    if(a[idx] != 0 && abs(a[idx] - lst) <= 1) add(ans, go(idx + 1, a[idx]));
    else if(a[idx] == 0) {
        for(int j = max(1, lst - 1); j <= min(m, lst + 1); j++) {
            add(ans, go(idx + 1, j)); 
        }
    }
    return dp[idx][lst] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    if(a[0] != 0) {
        ans = go(0, a[0]);
    } else {
        for(int i = 1; i <= m; i++) add(ans, go(1, i));
    }
    cout << ans << endl;
    return 0;
}