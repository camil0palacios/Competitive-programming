#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll oo = 1e18;
const int MXN = 25;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = oo;
    for(int i = 0; i < (1 << n); i++) {
        ll x = 0, y = 0;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) x += a[j];
            else y += a[j]; 
        } 
        ans = min(ans, abs(x - y));
    }
    cout << ans << endl;
    return 0;
}