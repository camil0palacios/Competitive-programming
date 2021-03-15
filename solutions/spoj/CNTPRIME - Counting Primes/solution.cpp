#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MXN = 1e6 + 5;
bool sieve[MXN];
int a[MXN];
int st[MXN], lazy[MXN];

void cal() {
    for(int i = 0; i < MXN; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i < MXN; i++)
        if(sieve[i]) 
            for(ll j = 1LL*i*i; j < MXN; j += i)
                sieve[j] = 0;
}

void build(int p, int l, int r) {
    lazy[p] = 0;
    if(l == r) {
        st[p] = sieve[a[l]];
        return;
    }
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    st[p] = st[left] + st[right];
}

void push(int p, int l, int r) {
    if(!lazy[p]) return;
    if(lazy[p] == -1) st[p] = 0;
    else st[p] = r - l + 1;
    if(l != r) {
        int left = p << 1, right = left + 1;
        lazy[left] = lazy[p], lazy[right] = lazy[p]; 
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int val) {
    push(p, l, r);
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr) {
        lazy[p] = val;
        push(p, l, r);
        return;
    } 
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    update(left, l, mid, ql, qr, val);
    update(right, mid + 1, r, ql, qr, val);
    st[p] = st[left] + st[right];
}

int query(int p, int l, int r, int ql, int qr) {
    push(p, l, r);
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    int p1 = query(left, l, mid, ql, qr);
    int p2 = query(right, mid + 1, r, ql, qr); 
    st[p] = st[left] + st[right];
    return p1 + p2;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while(q--) {
        int op, l, r;
        cin >> op >> l >> r;
        l--, r--;
        if(op == 1) {
            cout << query(1, 0, n - 1, l, r) << endl; 
        } else {
            int v;
            cin >> v;
            v = sieve[v] ? 1 : -1;
            update(1, 0, n - 1, l, r, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ":" << endl;
        solve();
    }
    return 0;
}