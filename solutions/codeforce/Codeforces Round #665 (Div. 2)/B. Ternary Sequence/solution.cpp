#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// 2 1 = 2
// 1 0 = 0 2 = 0 
// 1 2 = -2

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int x[2], y[2], z[2];
        cin >> x[0] >> y[0] >> z[0];
        cin >> x[1] >> y[1] >> z[1];
        int ans = 0;
        int m = min(x[0], z[1]);
        x[0] -= m;
        z[1] -= m;
        m = min(y[0], x[1]);
        y[0] -= m;
        x[1] -= m;
        m = min(z[0], y[1]);
        z[0] -= m;
        y[1] -= m;
        ans += m * 2;
        ans -= min(y[0], z[1]) * 2;
        cout << ans << endl;
    }
    return 0;
}