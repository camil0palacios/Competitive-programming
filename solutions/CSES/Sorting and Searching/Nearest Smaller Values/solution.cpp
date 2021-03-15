#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

struct segmenTree {
    int n;
    vi st;
    segmenTree(int n): n(n) { st.assign(n*4, -1); }
    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
    void update(int p, int l, int r, int idx, int val) {
        if(idx < l || r < idx) return;
        if(l == r) {
            st[p] = val;
            return;
        }
        int m = (l + r) >> 1, left = p << 1, right = left + 1;
        update(left, l, m, idx, val);
        update(right, m+1, r, idx, val);
        st[p] = max(st[left], st[right]);
    }
    int query(int l, int r) { return query(1, 0, n-1, l, r); }
    int query(int p, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return -1;
        if(ql <= l && r <= qr) return st[p];
        int m = (l + r) >> 1, left = p << 1, right = left + 1;
        return max(query(left, l, m, ql, qr), query(right, m+1, r, ql, qr));         
    }
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vi x(n), y(n);
    fori(i,0,n) cin >> x[i], y[i] = x[i];
    sort(all(y));
    map<int,int> m;
    int cnt = 0;
    fori(i,0,n) {
        if(m.count(y[i])) continue; 
        m[y[i]] = cnt++;
    }
    fori(i,0,n) x[i] = m[x[i]];
    // fori(i,0,n) cout << x[i] << ' ';
    segmenTree st(cnt+1);
    fori(i,0,n) {
        int val = st.query(0, x[i]-1);
        if(val != -1) cout << val+1 << ' ';
        else cout << 0 << ' ';
        st.update(x[i], i);
    }
    return 0; 
}