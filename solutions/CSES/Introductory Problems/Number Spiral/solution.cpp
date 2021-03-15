#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> y >> x;
        ll sq = max(x - 1, y - 1);
        ll ans = sq * sq;
        if(sq & 1) {
            if(x <= sq) ans += sq + 1 + abs(sq + 1 - x);
            else ans += y;
        } else {
            if(y <= sq) ans += sq + 1 + abs(sq + 1 - y);
            else ans += x;
        }
        cout << ans << endl;
    }
    return 0;
}