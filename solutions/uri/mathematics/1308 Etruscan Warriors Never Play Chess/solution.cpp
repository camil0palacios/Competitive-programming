#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = sqrt((double)2*n + 1/4.0) - 1/2.0;
        cout << ans << endl;
    }
    return 0;
}