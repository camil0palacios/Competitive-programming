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

const int Mxn = 1e5 + 5;
int st[4*Mxn];
string s;

void build(int p, int l, int r) {
    if(l == r) {
        st[p] = (1 << (s[l] - 'a'));
    } else {
        int m = (l + r) >> 1, left = p << 1, right = left + 1;
        build(left, l, m);
        build(right, m+1, r);
        st[p] = st[left] | st[right];        
    }
}

void update(int p, int l, int r, int idx, int val) {
    if(idx < l || r < idx) return;
    if(l == r){
        st[p] = (1 << val);
        return;
    }
    int m = (l + r) >> 1, left = p << 1, right = left + 1;
    update(left, l, m, idx, val);
    update(right, m+1, r, idx, val);
    st[p] = st[left] | st[right];
}

int query(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return st[p];
    int m = (l + r) >> 1, left = p << 1, right = left + 1;
    return query(left, l, m, ql, qr) | query(right, m+1, r, ql, qr);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    int n = sz(s);
    build(1, 0, n-1);
    int q;
    cin >> q;
    while(q--) {
        int t, l, r;
        cin >> t >> l; l--;
        if(t == 1) {
            char c; 
            cin >> c;
            update(1, 0, n-1, l, c-'a');
        } else {
            cin >> r; r--;
            int x = query(1, 0, n-1, l, r);
            x = __builtin_popcount(x);
            cout << x << endl;
        }
    }
    return 0; 
}