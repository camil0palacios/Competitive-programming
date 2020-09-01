#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;
        if(x + y <= k) {
            cout << x << ' ' << y << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}