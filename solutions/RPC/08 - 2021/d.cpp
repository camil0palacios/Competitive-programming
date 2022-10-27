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

typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll oo = 1e14;
const int Mxn = 2e5 + 5;
ll a[Mxn];
ll st[4*Mxn][2];

void bld(int p, int l, int r) {
    if(l == r) st[p][0] = st[p][1] = a[l];
    else {
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        bld(left, l, mid);
        bld(right, mid+1, r);
        st[p][0] = min(st[left][0], st[right][0]);
        st[p][1] = max(st[left][1], st[right][1]);    
    }
}

void upd(int p, int l, int r, int idx, ll val) {
    if(idx < l || r < idx) return;
    if(l == r) st[p][0] = st[p][1] = val;
    else {
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        upd(left, l, mid, idx, val);
        upd(right, mid+1, r, idx, val);
        st[p][0] = min(st[left][0], st[right][0]);
        st[p][1] = max(st[left][1], st[right][1]);    
    }
}

ii qry(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return mp(oo, -oo);
    if(ql <= l && r <= qr) return mp(st[p][0], st[p][1]);
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    auto lans = qry(left, l, mid, ql, qr);
    auto rans = qry(right, mid+1, r, ql, qr);
    return mp(min(lans.ft, rans.ft), max(lans.sd, rans.sd));
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    fore(i,1,n) cin >> a[i];
    bld(1, 1, n);
    fori(i,0,q) {
        string c;
        cin >> c;
        if(c[0] == 'M') {
            int l, r;
            cin >> l >> r;
            auto ans = qry(1, 1, n, l, r);
            if(c[2] == 'N') cout << ans.ft << endl;
            else cout << ans.sd << endl;
        } 
        else {
            int idx, val;
            cin >> idx >> val;
            upd(1, 1, n, idx, val);
        } 
    } 
    return 0; 
}