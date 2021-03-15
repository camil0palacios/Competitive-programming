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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 10;
// segment tree
int st[4*Mxn];
void build(int p, int l, int r) {
    if(l == r) st[p] = 1;
    else {
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        build(left, l, mid);
        build(right, mid+1, r);
        st[p] = st[left] + st[right];
    }
}
void update(int p, int l, int r, int idx, int val) {
    if(idx < l || r < idx) return;
    if(l == r) {
        st[p] = val;
        return;
    }
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    update(left, l, mid, idx, val);
    update(right, mid+1, r, idx, val);
    st[p] = st[left] + st[right];
}
int query(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    return query(left, l, mid, ql, qr) + query(right, mid+1, r, ql, qr);    
}
int find(int p, int l, int r, int k) {
    if(l == r) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    if(k <= st[left]) return find(left, l, mid, k); 
    return find(right, mid+1, r, k - st[left]);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    build(1, 0, n-1);
    int pos = 0;
    fori(i,0,n) {
        int s = (n - i) % k;
        int x = query(1, 0, n-1, 0, pos);
        int idx = find(1, 0, n-1, (x + s - 1 + n) % n);
        update(1, 0, n-1, idx, 0);
        cout << idx+1 << ' ';
        pos = idx;
    }
    return 0;
}