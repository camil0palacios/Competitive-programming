#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    if(n & 1) {
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ans += abs((ll)a[n / 2] - a[i]);
        }
        cout << ans << endl;
    } else {
        ll x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            x += abs((ll)a[n/2] - a[i]);
            y += abs((ll)a[(n/2) - 1] - a[i]);
        }
        cout << min(x, y) << endl;
    }
    return 0;
}