#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    map<ll, ll> dp;
    ll ans = 0;
    for(auto & i: a) {
        int p = i.first, h = i.second;
        dp[p + h] = max(dp[p + h], dp[p] + h);
        dp[p] = max(dp[p], dp[p - h] + h);
        ans = max({ans, dp[p], dp[p + h]});
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}