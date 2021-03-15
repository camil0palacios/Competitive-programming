#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ll mx = -INF, cur = -INF;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cur = max(x, cur + x);
        mx = max(mx, cur);
    }
    cout << mx << endl;
    return 0;
}