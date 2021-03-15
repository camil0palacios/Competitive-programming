#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];
ll t[MXN];

void add(ll x, int idx) {
    while(idx < MXN) {
        t[idx] += x;
        idx += idx & -idx;
    }
}

ll query(int idx) {
    ll ans = 0;
    while(idx > 0) {
        ans += t[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        add(a[i], i);
    }
    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) {
            add(-a[l], l);
            a[l] = r;
            add(a[l], l);
        } else {
            cout << query(r) - query(l - 1) << endl;
        }
    }
    return 0;
}