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
        ll ans = k + (k - 1) / (n - 1);
        cout << ans << endl;
    }
    return 0;
}