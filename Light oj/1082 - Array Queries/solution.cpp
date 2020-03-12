#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9;
int a[MAXN];
int st[4 * MAXN];

void build(int p, int l, int r) {
    if(l == r) {
        st[p] = a[l];
    } else {
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        build(left, l, mid);
        build(right, mid + 1, r);
        st[p] = min(st[left], st[right]);
    }
}

int query(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return INF;
    if(ql <= l && r <= qr) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    return min(query(left, l, mid, ql, qr), query(right, mid + 1, r, ql, qr));
}

void sol() {
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 0, n - 1);
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        cout << query(1, 0, n - 1, l, r) << endl;
    }
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ":" << endl;
        sol();
    }
    return 0;
}