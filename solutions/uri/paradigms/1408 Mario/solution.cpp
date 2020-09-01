#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int n, l, a[MXN], tree[2*MXN];

int update(int idx, int val) {
    while(idx < 2*MXN) {
        tree[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int ans = 0;
    while(idx > 0) {
        ans += tree[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> l && (n || l)) {
        memset(tree, 0, sizeof tree);
        for(int i = 0; i < l; i++) {
            cin >> a[i];
        }
        vector<int> b;
        for(int i = 0; i < l; i++) {
            b.emplace_back(a[i]);
            b.emplace_back(a[i] + n - 1);
        }
        sort(b.begin(), b.end());
        int num = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < b.size(); i++) {
            if(i && b[i] == b[i - 1]) continue;
            m[b[i]] = ++num;
        }
        for(int i = 0; i < l; i++) {
            update(m[a[i]], 1);
        }
        int ans = l;
        for(int i = 0; i < l; i++) {
            int l = m[a[i]], r = m[a[i] + n - 1];
            ans = min(ans, n - (query(r) - query(l - 1)));
        }
        cout << ans << endl;
    }
    return 0;
}