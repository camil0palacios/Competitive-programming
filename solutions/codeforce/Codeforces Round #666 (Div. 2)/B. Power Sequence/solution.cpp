#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e5 + 5;
ll a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    sort(a, a + n);
    ll ans = 1e18;
    for(int i = 1; i <= 1e18; i++) {
        ll p = 1, tmp = 0;
        bool ok = 1;
        for(int j = 0; j < n; j++) {
            tmp += abs(p - a[j]);
            if(p < 1e18 / i) p *= i; 
            else {
                ok = 0; break;
            }
        }
        if(ok) ans = min(ans, tmp);
        else break;
    }
    cout << ans << endl;
    return 0;
}