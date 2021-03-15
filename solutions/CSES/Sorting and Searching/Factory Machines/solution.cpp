#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = -1;
    ll l = 0, r = 1e18;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        ll cnt = 0;
        for(int i = 0; i < n && cnt < k; i++) {
            cnt += mid / a[i];
        }
        if(cnt >= k) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}