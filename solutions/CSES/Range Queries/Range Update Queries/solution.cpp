#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];
ll st[MXN*4];
ll lazy[MXN*4];

void build(int node, int l, int r) {
    lazy[node] = 0;
    if(l == r) {
        st[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1, left = node << 1, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    st[node] = st[left] + st[right];
}

void push(int node, int l, int r) {
    if(!lazy[node]) return;
    st[node] += lazy[node] * (r - l + 1);
    if(l != r) {
        int left = node << 1, right = left + 1;
        lazy[left] += lazy[node], lazy[right] += lazy[node]; 
    }
    lazy[node] = 0;
}

void update(int node, int l, int r, int ql, int qr, ll val) {
    push(node, l, r);
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr) {
        lazy[node] = val;
        push(node, l, r);
        return;
    }
    int mid = (l + r) >> 1, left = node << 1, right = left + 1;
    update(left, l, mid, ql, qr, val);
    update(right, mid + 1, r, ql, qr, val);
    st[node] = st[left] + st[right];
}

ll query(int node, int l, int r, int k) {
    push(node, l, r);
    if(l == r) return st[node];
    int mid = (l + r) >> 1, left = node << 1, right = left + 1;
    ll ans = 0;
    if(k <= mid) ans = query(left, l, mid, k);
    else ans = query(right, mid + 1, r, k);
    st[node] = st[left] + st[right];    
    return ans;
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
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, val;
            cin >> l >> r >> val; l--, r--;
            update(1, 0, n - 1, l, r, val);
        } else {  
            int k;
            cin >> k;
            k--;
            cout << query(1, 0, n - 1, k) << endl;
        }
    }
    return 0;
}