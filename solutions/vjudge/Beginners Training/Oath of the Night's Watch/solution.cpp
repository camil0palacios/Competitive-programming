#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    int mn = 1e9, mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]), mx = max(mx, a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (mn < a[i] && a[i] < mx);
    }
    cout << ans << endl;
    return 0;
}