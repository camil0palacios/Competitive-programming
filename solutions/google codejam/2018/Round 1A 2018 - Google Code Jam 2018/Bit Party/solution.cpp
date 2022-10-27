#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1010;
ll r, b, c;
ll m[MXN], s[MXN], p[MXN];

ll check(ll t) {
    ll cap[c];
    for(int i = 0; i < c; i++) {
        cap[i] = max(0LL, min(m[i], (t - p[i]) / s[i]));
    }
    sort(cap, cap + c, greater<ll>());
    ll sum = 0;
    for(int i = 0; i < r; i++) {
        sum += cap[i];
    }   
    return sum;
}

void sol() {
    cin >> r >> b >> c;
    for(int i = 0; i < c; i++) {
        cin >> m[i] >> s[i] >> p[i];
    }
    ll l = 1, r = 2e18;
    while(r - l > 1) {
        ll mid = (l + r) >> 1;
        if(b <= check(mid)){
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}