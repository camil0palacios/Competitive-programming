#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll b_pow(ll a, int b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int n, x;
ll dp[110][1001];

ll Dp(int a, int sum) {
    if(sum == x) return 1;
    if(dp[a][sum] != -1) return dp[a][sum];
    ll ans = 0;
    if(sum + b_pow(a, n) <= x)
        ans = Dp(a + 1, sum) + Dp(a + 1, sum + b_pow(a, n));
    return dp[a][x] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> x >> n;
    memset(dp, -1, sizeof dp);
    cout << Dp(1, 0) << endl;
    return 0;
}