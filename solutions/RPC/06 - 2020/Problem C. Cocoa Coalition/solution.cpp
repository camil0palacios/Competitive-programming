#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

bool cal(ll n, ll m, ll a) {
    bool ok = 0;
    for(int i = 1; i <= n; i++) {
        ll x = a - (i * m);
        ll l = 1, r = m, ans = -1;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(mid * (n - i) <= x) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        if(ans != -1 && ans * (n - i) == x) ok = 1;
    
    }
    return ok;
}

bool cal2(ll n, ll m, ll a) {
    bool ok = 0;
    for(int i = 1; i <= n; i++) {
        ll l = 1, r = m, ans = -1;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(mid * i <= a) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        if(ans != -1 && ans * i == a) ok = 1;   
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m, a;
    cin >> n >> m >> a;
    bool ok = 0;
    for(int i = 0; i <= n; i++) {
        ok |= m * i == a;
    }
    for(int i = 0; i <= m; i++) {
        ok |= n * i == a;
    }
    if(ok) cout << 1 << endl;
    else if(cal2(n, m, a) || cal2(m, n, a) || cal(n, m, a) || cal(m, n, a)) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}