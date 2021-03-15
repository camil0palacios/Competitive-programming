#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

template<class T>
struct segment_tree { 
    int n;
    vector<T> st, lazy;
    segment_tree() {}
    segment_tree(int n): n(n) { st.resize(4*n); lazy.resize(4*n); }
    void build(vector<T> & a) {
        n = sz(a);
        st.resize(4*n), lazy.resize(4*n);
        build(1, 0, n-1, a);
    }
    void build(int p, int l, int r, vector<T> & a) {
        if(l == r) {
            st[p] = a[l];
            return;
        }
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        build(left, l, mid, a);
        build(right, mid+1, r, a);
        st[p] = st[left] + st[right];
    }
    void push(int p, int l, int r) {
        if(!lazy[p]) return;
        st[p] += lazy[p]*(r - l + 1);
        if(l != r) {
            int left = p << 1, right = left + 1;
            lazy[left] += lazy[p], lazy[right] += lazy[p]; 
        }
        lazy[p] = 0;
    }
    void update(int l, int r, T val) { update(1, 0, n-1, l, r, val); }
    void update(int p, int l, int r, int ql, int qr, T val) {
        push(p, l, r);
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr) {
            lazy[p] += val;
            push(p, l, r);
            return;
        }
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        update(left, l, mid, ql, qr, val);
        update(right, mid+1, r, ql, qr, val);
        st[p] = st[left] + st[right];
    }
    T query(int l, int r) { return query(1, 0, n-1, l, r); }
    T query(int p, int l, int r, int ql, int qr) {
        push(p, l, r);
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return st[p];
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        T al = query(left, l, mid, ql, qr);
        T ar = query(right, mid+1, r, ql, qr);
        // st[p] = st[left] + st[right];
        return al + ar;
    }
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        segment_tree<ll> st(n);
        while(q--) {
            int t, l, r, v;
            cin >> t >> l >> r;
            l--, r--;
            if(!t) {
                cin >> v;
                st.update(l, r, v);
                // update(1, 0, n-1, l, r, v);
            } 
            // else cout << query(1, 0, n-1, l, r) << endl;
            else cout << st.query(l, r) << endl;
        }
    }
    return 0; 
}