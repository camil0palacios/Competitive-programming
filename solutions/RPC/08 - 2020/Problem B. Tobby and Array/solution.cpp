#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;

typedef vector<int> vi;

const int MXN = 1e6 + 5;
int a[MXN];
vi st[4 * MXN];

void merge(vi & v, vi & a, vi & b) {
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) v.emplace_back(a[i++]);
        else v.emplace_back(b[j++]);
    }
    while(i < a.size()) v.emplace_back(a[i++]);
    while(j < b.size()) v.emplace_back(b[j++]);
}

void build(int p, int l, int r, vector<pair<int,int>>& pos) {
    st[p].clear();
    if(l == r) {
        st[p].emplace_back(pos[l].second);
        return;
    }
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    build(left, l, mid, pos);
    build(right, mid + 1, r, pos);
    merge(st[p], st[left], st[right]);
}

int query(int p, int l, int r, int ql, int qr, int k) {
    if(l == r) {
        return st[p][0];
    }
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    int high = upper_bound(all(st[left]), qr) - st[left].begin();
    int low = lower_bound(all(st[left]), ql) - st[left].begin();
    int m = high - low;
    if(m >= k) {
        return query(left, l, mid, ql, qr, k);
    } else {
        return query(right, mid + 1, r, ql, qr, k - m);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    while(cin >> n >> q) {
        vector<pair<int, int>> pos(n); 
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            pos[i].first = a[i], pos[i].second = i;
        }
        sort(all(pos));
        build(1, 0, n - 1, pos);
        for(int i = 0; i < q; i++) {
            int ql, qr, k;
            cin >> ql >> qr >> k;
            ql--, qr--;
            int idx = query(1, 0, n - 1, ql, qr, k);
            cout << a[idx] << endl;
        }
    }
    return 0;
}