#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x > y)swap(x, y);
        ll dif = y - x;
        ll ans = min(a * dif + b * x, a * dif + b * y);
        ans = min(ans, min(b * x + a * dif, a * x + a * y));
        cout << ans << endl;
    }
    return 0;
}