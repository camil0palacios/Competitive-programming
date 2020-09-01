#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll ans = 1e9;
        for(ll i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if(i <= k) ans = min(ans, n / i);
                if(n / i != i) {
                    ll tmp = n / i;
                    if(tmp <= k)
                        ans = min(ans, n / tmp);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}