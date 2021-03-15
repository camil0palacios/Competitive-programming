#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll n;
vector<int> v;
ll dp[55][2][55];

ll dptop(int idx, int top, int sum) {
    if(idx == v.size()) return sum;
    if(dp[idx][top][sum] != -1) return dp[idx][top][sum];
    ll ans = 0;
    int mx = top ? v[idx] : 1;
    for(int i = 0; i <= mx; i++) {
        ans += dptop(idx + 1, top && i == mx, sum + i);
    }
    return dp[idx][top][sum] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(ll i = n; i; i >>= 1) {
        v.emplace_back(i & 1);
    }
    reverse(v.begin(), v.end());
    cout << dptop(0, 1, 0) << endl;
    return 0;
}