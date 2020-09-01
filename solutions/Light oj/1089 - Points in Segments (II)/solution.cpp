#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 510000;
int a[MAXN], b[MAXN], pt[MAXN];
int Q[MAXN];
int st[MAXN * 4], lazy[MAXN * 4];

void read(int & x) {
    scanf("%d", &x);
}

void print(int & x) {
    printf("%d\n", x);
}

void pushDown(int p, int l, int r) {
    st[p] += lazy[p];
    if(l != r) {
        int left = p << 1, right = left + 1;
        lazy[left] += lazy[p];
        lazy[right] += lazy[p];
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int val) {
    if(qr < l || r < ql)return;
    if(lazy[p])pushDown(p, l, r);
    if(ql <= l && r <= qr) {
        lazy[p] += val;
        pushDown(p, l, r);
        return;
    }
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    update(left, l, mid, ql, qr, val);
    update(right, mid + 1, r, ql, qr, val);
    st[p] = st[left] + st[right];
}

int query(int p, int l, int r, int idx) {
    if(idx < l || r < idx)return 0;
    if(lazy[p])pushDown(p, l, r);
    if(l == r) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    return query(left, l, mid, idx) + query(right, mid + 1, r, idx);
}

int bs(int x, int n) {
    int l = 0, r = n;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if(pt[mid] <= x) l = mid;
        else r = mid;
    } 
    return l;
}

void sol() {
    int n, q;
    read(n); read(q);
    int it = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        pt[it++] = a[i];
        pt[it++] = b[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> Q[i];
        pt[it++] = Q[i];
    }
    sort(pt, pt + it);
    int tmp = 1;
    for(int i = 0; i < it; i++) {
        if(pt[i] != pt[i - 1])pt[tmp++] = pt[i];
    }
    it = tmp;
    memset(st, 0, sizeof st);
    memset(lazy, 0, sizeof lazy);
    for(int i = 0; i < n; i++) {
        update(1, 0, it - 1, bs(a[i], it), bs(b[i], it), 1);
    }
    for(int i = 0; i < q; i++) {
        int ans = query(1, 0, it - 1, bs(Q[i], it)); 
        print(ans);
    }
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    read(t);
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ':' << endl;
        sol();
    }
    return 0;
}