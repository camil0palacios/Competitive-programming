#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int MXN = 100005;
int a[MXN]; ii b[MXN];
vi st[MXN * 3];

void build(int p, int l, int r) {
    if(l == r) {
        st[p].emplace_back(b[l].ss);
        return;
    }
    int mid = (l + r) / 2, left = p * 2, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    merge(all(st[left]), all(st[right]), back_inserter(st[p]));

}

int query(int p, int l, int r, int ql, int qr, int k) {
    if(l == r) {
        return st[p].back();
    }
    int mid = (l + r) / 2, left = p * 2, right = left + 1;
    int sz = upper_bound(all(st[left]), qr) - lower_bound(all(st[left]), ql);
    if(sz >= k) {
        return query(left, l, mid, ql, qr, k);
    } else {
        return query(right, mid + 1, r, ql, qr, k - sz);
    }
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }
    sort(b + 1, b + n + 1);
    build(1, 1, n);
    while(q--) {
        int l, r, k; 
        cin >> l >> r >> k;
        int idx = query(1, 1, n, l, r, k);
        cout << a[idx] << endl;
    }
    return 0;
}

/*        
           0 1 2 3 4 5 6
            /        \
        0 2 4 6     1 3 5
        /    \       /   \
    0 2     4 6     1 3   5      
    / \     / \     / \
   0   2   4   6   1  3
    
    0 1 2 3 4 5 6
    1 5 2 6 3 7 4

    0 2 4 6 1 3 5
    1 2 3 4 5 6 7
*/