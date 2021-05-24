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

const int Mxn = 1e5 + 5;
int a[Mxn];

int st[4*Mxn];
void upd(int p, int l, int r, int idx, int val) {
    if(idx < l || r < idx) return;
    if(l == r) st[p] = val;
    else {
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        upd(left, l, mid, idx, val);
        upd(right, mid+1, r, idx, val);
        st[p] = max(st[left], st[right]);
    }
}
int qry(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left + 1;
    return max(qry(left, l, mid, ql, qr), qry(right, mid+1, r, ql, qr));
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    cin >> n;
    fore(i,1,n) cin >> a[i];
    int ans = 0;
    forr(i,n,1) {
        int x = qry(1, 1, n, a[i], n);
        ans = max(ans, x+1);
        upd(1, 1, n, a[i], x+1);
    }
    cout << ans << endl;
    return 0; 
}