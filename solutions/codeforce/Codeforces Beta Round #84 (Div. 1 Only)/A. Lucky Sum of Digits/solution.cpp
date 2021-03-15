#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e6 + 5;
int n;
int dp[MXN];
string ans;

int a[2] = {7, 4};

bool go(int s) {
    if(s == n) return 1;
    if(dp[s] != -1) return dp[s];
    for(int i = 0; i < 2; i++) {
        if(s + a[i] <= n && go(s + a[i])) {
            ans += char(a[i] + '0');
            return dp[s] = 1;
        }
    }
    return dp[s] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    memset(dp, -1, sizeof dp);
    if(go(0)) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}