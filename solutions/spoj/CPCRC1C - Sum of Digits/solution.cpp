#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string s;
ll dp[10][2][100];

ll dptop(int idx, bool top, int sum) {
    if(idx == s.size()) return sum;
    if(dp[idx][top][sum] != -1) return dp[idx][top][sum];
    ll ans = 0, mx = top ? s[idx] - '0' : 9;
    for(int i = 0; i <= mx; i++) {
        ans += dptop(idx + 1, top && i == mx, sum + i);
    }
    return dp[idx][top][sum] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    while(cin >> a >> b && a != -1 && b != -1) {
        s = to_string(a - 1);
        memset(dp, -1, sizeof dp);
        ll ans = dptop(0, 1, 0);
        s = to_string(b);
        memset(dp, -1, sizeof dp);
        cout << dptop(0, 1, 0) - ans << endl;
    }
    return 0;
}