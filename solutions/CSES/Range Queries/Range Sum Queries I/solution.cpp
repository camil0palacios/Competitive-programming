#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
ll t[MXN];

void add(int idx, int x) {
    while(idx < MXN) {
        t[idx] += x;
        idx += idx & -idx;
    }
}

ll sum(int idx) {
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
        int x; cin >> x;
        add(i, x);
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << sum(r) - sum(l - 1) << endl;
    }
    return 0;   
}