#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    unordered_map<int, int> dpl, dpr;
    for(int i = 0; i < n; i++) {
        int p = a[i].first, h = a[i].second;
        dpr[p + h] = max(dpr[p + h], dpr[p] + h);
    }
    for(int i = n - 1; i >= 0; i--) {
        int p = a[i].first, h = a[i].second;
        dpl[p - h] = max(dpl[p - h], dpl[p] + h);
    } 
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int p = a[i].first, h = a[i].second;
        ans = max(ans, dpl[p] + dpr[p]);
        ans = max(ans, dpr[p + h] + dpl[p + h]);
        ans = max(ans, dpr[p - h] + dpl[p - h]);

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