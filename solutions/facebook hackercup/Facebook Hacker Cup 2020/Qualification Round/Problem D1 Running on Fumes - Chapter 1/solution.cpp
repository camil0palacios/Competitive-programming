#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll INF = 1e18;
const int MXN = 1e6 + 5;
ll c[MXN];
ll st[MXN*4];

void build(int p, int l, int r) {
    if(l == r) {
        st[p] = INF;
        return;
    }
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    st[p] = min(st[left], st[right]);
}

void update(int p, int l, int r, int idx, ll val) {
    if(idx < l || r < idx) return;
    if(l == r) {
        st[p] = val;
        return;
    }
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    update(left, l, mid, idx, val);
    update(right, mid + 1, r, idx, val);
    st[p] = min(st[left], st[right]);
}

ll query(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return INF;
    if(ql <= l && r <= qr) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    return min(query(left, l, mid, ql, qr), query(right, mid + 1, r, ql, qr));
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    build(1, 0, n - 1);
    update(1, 0, n - 1, n - 1, 0);
    for(int i = n - 2; i >= 0; i--) {
        if(c[i])
            update(1, 0, n - 1, i, query(1, 0, n - 1, i, min(i + m, n - 1)) + c[i]);
    }
    ll ans = query(1, 0, n - 1, 0, m);
    cout << (ans != INF ? ans : -1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}