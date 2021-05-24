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

const ll oo = 1e16;
const int Mxn = 2e5 + 5;
ll a[Mxn];

struct Node { ll sum, pf; Node(){} };
Node st[4*Mxn];

void bld(int p, int l, int r) {
    if(l == r) {
        st[p].sum = a[l];
        st[p].pf = a[l];
    } else { 
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        bld(left, l, mid);
        bld(right, mid+1, r);
        st[p].sum = st[left].sum + st[right].sum;
        st[p].pf = max(st[left].pf, st[left].sum + st[right].pf);
    }
}
void upd(int p, int l, int r, int idx, int val) {
    if(idx < l || r < idx) return;
    if(l == r) {
        st[p].sum = val;
        st[p].pf = val;
    } else {
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        upd(left, l, mid, idx, val);
        upd(right, mid+1, r, idx, val);
        st[p].sum = st[left].sum + st[right].sum;
        st[p].pf = max(st[left].pf, st[left].sum + st[right].pf);
    }
}
Node qry(int p, int l, int r, int ql, int qr) {
    Node ans;
    ans.sum = ans.pf = 0;
    if(qr < l || r < ql) return ans;
    if(ql <= l && r <= qr) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    Node ans_l = qry(left, l, mid, ql, qr);
    Node ans_r = qry(right, mid+1, r, ql, qr);
    ans.sum = ans_l.sum + ans_r.sum;
    ans.pf = max(ans_l.pf, ans_l.sum + ans_r.pf);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    fore(i,1,n) cin >> a[i];
    bld(1, 1, n);
    fori(i,0,q) {
        int t;
        cin >> t;
        if(t == 1) {
            int p, v;
            cin >> p >> v;
            upd(1, 1, n, p, v);
        } else {
            int l, r;
            cin >> l >> r;
            Node ans = qry(1, 1, n, l, r);
            cout << max(0ll, ans.pf) << endl;
        }
    }
    return 0; 
}