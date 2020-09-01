#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e6 + 10;
int n, k, d[MXN], profit[MXN];
ll st[MXN * 4];

void update(int p, int l, int r, int idx, ll val) {
    if(idx < l || r < idx) return;
    if(l == r) {
        st[p] = val;
        return;
    }
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    update(left, l, mid, idx, val);
    update(right, mid + 1, r, idx, val);
    st[p] = max(st[left], st[right]);
}

ll query(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    return max(query(left, l, mid, ql, qr), query(right, mid + 1, r, ql, qr));
}

// dp[i] = max(dp[j]) + prf[i] where a[i] - a[j] >= k 

ll Dp() {
    memset(st, 0, sizeof st);
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        int l = i, r = n - 1;
        while(r - l > 1) {
            int mid = (l + r) >> 1;
            if(d[mid] - d[i] >= k) r = mid;
            else l = mid;
        }
        if(d[r] - d[i] >= k) {
            update(1, 0, n - 1, i, query(1, 0, n - 1, r, n - 1) + profit[i]);
        } else {
            update(1, 0, n - 1, i, profit[i]);
        }
        ans = max(ans, query(1, 0, n - 1, i, n - 1));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    for(int cs = 0; cs < t; cs++) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> d[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> profit[i];
        }
        cout << Dp() << endl;
    }
    return 0;
}