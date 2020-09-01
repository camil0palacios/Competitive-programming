#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = (1e5 + 5) * 2;
int n, a[MAXN];
int st[MAXN * 4];

void build(int p, int l, int r) {
    if(l == r){
        st[p] = a[l];
    } else {
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        build(left, l, mid);
        build(right, mid + 1, r);
        st[p] = max(st[left], st[right]);
    }
}

int query(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr)return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    return max(query(left, l, mid, ql, qr), query(right, mid + 1, r, ql, qr));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        for(int i = 0; i < n; i++) {
            a[i + n] = a[i];
        }
        build(1, 0, 2*n - 1);
        int ans = 0, half = (n + 1) / 2;
        for(int i = 0; i < n; i++){ 
            int l = i, r = l + half - 1;
            int q = query(1, 0, 2*n - 1, l, r);
            ans += q < mx;
        }
        cout << ans << endl;
    }
}