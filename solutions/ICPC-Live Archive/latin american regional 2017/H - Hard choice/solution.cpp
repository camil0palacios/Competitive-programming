#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c, d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f) {
        int ans = 0;
        if(a < d) ans += d - a;
        if(b < e) ans += e - b;
        if(c < f) ans += f - c;
        cout << ans << endl;
    }
    return 0;
}