#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
const int INF = 1e9;
int a[MXN];
int st[MXN*4];

void build(int node, int l, int r) {
    if(l == r) {
        st[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1, left = node << 1, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    st[node] = st[left] ^ st[right];
}

void update(int node, int l, int r, int idx, int val) {
    if(idx < l || r < idx) return;
    if(l == r) {
        st[node] = val;
        return;
    }
    int mid = (l + r) >> 1, left = node << 1, right = left + 1;
    update(left, l, mid, idx, val);
    update(right, mid + 1, r, idx, val);
    st[node] = st[left] ^ st[right];
}

int query(int node, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return st[node];
    int mid = (l + r) >> 1, left = node << 1, right = left + 1;
    return query(left, l, mid, ql, qr) ^ query(right, mid + 1, r, ql, qr);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(1, 0, n - 1, l, r) << endl;
    }
    return 0;
}