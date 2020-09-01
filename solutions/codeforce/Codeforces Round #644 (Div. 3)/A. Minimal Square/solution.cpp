#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int ans = 100000;
        if(2*a >= b) ans = min(ans, 4*a*a);
        if(2*b >= a) ans = min(ans, 4*b*b);
        if(a >= 2*b) ans = min(ans, a*a);
        if(b >= 2*a) ans = min(ans, b*b);
        cout << ans << endl;
    }
    return 0;
}