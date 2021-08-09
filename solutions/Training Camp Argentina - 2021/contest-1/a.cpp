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

const int Mxn = 2e5 + 5;
int n, k, a, b, q;
ll st[Mxn*4][2];

void upd(int p, int l, int r, int idx, int val) {
    if(idx < l || r < idx) return;
    if(l == r) {
        st[p][0] = min(1ll*b, st[p][0] + val);
        st[p][1] = min(1ll*a, st[p][1] + val);
    } else {
        int mid = (l+r) >> 1, left = p << 1, right = left+1;
        upd(left, l, mid, idx, val);
        upd(right, mid+1, r, idx, val);
        st[p][0] = st[left][0] + st[right][0];
        st[p][1] = st[left][1] + st[right][1];
    }
}
ll qry(int p, int l, int r, int ql, int qr, bool ok) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return st[p][ok];
    int mid = (l+r) >> 1, left = p << 1, right = left+1;
    return qry(left, l, mid, ql, qr, ok) + qry(right, mid+1, r, ql, qr, ok);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> a >> b >> q;
    fori(i,0,q) {
        int t;
        cin >> t;
        if(t == 1) {
            int d, ai;
            cin >> d >> ai;
            upd(1, 1, n, d, ai);
        } else {
            int p;
            cin >> p;
            int ans = 0;
            if(p-1 >= 1) ans = qry(1, 1, n, 1, p-1, 0); 
            if(p+k <= n) ans += qry(1, 1, n, p+k, n, 1);
            cout << ans << endl;
        }
    }
    return 0; 
}