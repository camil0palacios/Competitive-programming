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

const int Mxn = 3e5 + 5;
ii a[Mxn];
int st[4*Mxn];

void bld(int p, int l, int r) {
    if(l == r) st[p] = a[l].sd;
    else {
        int mid = (l + r) >> 1, left = p << 1, right = left+1;
        bld(left, l, mid);
        bld(right, mid+1, r);
        st[p] = max(st[left], st[right]); 
    }
}
int qry(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return st[p];
    int mid = (l + r) >> 1, left = p << 1, right = left+1;
    return max(qry(left, l, mid, ql, qr), qry(right, mid+1, r, ql, qr));
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin >> k;
    vi ans;
    fore(t,1,k) {
        int n; 
        cin >> n;
        bool pos = 0;
        fori(i,0,n) {
            int x; cin >> x;
            a[i] = {x, i};
        }
        sort(a, a+n);
        bld(1, 0, n-1);
        set<int> s;
        fori(i,0,n) {
            auto it = s.lower_bound(a[i].sd);
            if(it != s.end()) {
                int mx = qry(1, 0, n-1, i+1, n-1);
                if(*it < mx) pos |= 1;
            }
            s.insert(a[i].sd);
        }
        if(pos) ans.eb(t);
    }
    cout << sz(ans) << endl;
    for(auto & i : ans) cout << i << endl;
    return 0; 
}