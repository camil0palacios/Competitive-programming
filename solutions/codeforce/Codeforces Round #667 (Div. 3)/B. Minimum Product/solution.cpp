#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll ans = 1e18;
        for(int i = 0; i < 2; i++) {
            int da = min(n, a - x);
            int db = min(n - da, b - y);
            ans = min(ans, (a - da) * 1LL * (b - db));
            swap(a, b);
            swap(x, y);
        }
        cout << ans << endl;
    }
    return 0;
}