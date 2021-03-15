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

const int Mxn = 1e5 + 5;
unordered_map<int,int> m;
unordered_map<int,int> mr;

struct segmenTree {
    int n;
    vi st;
    segmenTree(int n): n(n) { st.assign(n*4, 0); }
    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
    void update(int p, int l, int r, int idx, int val) {
        if(idx < l || r < idx) return;
        if(l == r) {
            st[p] += val;
            return;
        }
        int m = (l + r) >> 1, left = p << 1, right = left + 1;
        update(left, l, m, idx, val);
        update(right, m+1, r, idx, val);
        st[p] = st[left] + st[right];
    }
    int findKth(int k) { return query(1, 0, n-1, k); }
    int query(int p, int l, int r, int k) {
        if(l == r) return l;
        int m = (l + r) >> 1, left = p << 1, right = left + 1;
        if(k <= st[left]) return query(left, l, m, k);
        return query(right, m+1, r, k - st[left]);
    }
    int sum() { return st[1]; }
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi x(n), y(n);
    fori(i,0,n) cin >> x[i], y[i] = x[i];
    sort(all(y));
    int cnt = 0;
    fori(i,0,n) {
        if(m.count(y[i])) continue;
        m[y[i]] = cnt;
        mr[cnt] = y[i];
        cnt++;
    }
    segmenTree st(cnt);
    fori(i,0,n) {
        if(i >= k) st.update(m[x[i - k]], -1);
        st.update(m[x[i]], 1);
        if(st.sum() >= k) {
            cout << mr[st.findKth((k + 1)/2)] << ' ';
        }
    }
    cout << endl;
    return 0; 
}