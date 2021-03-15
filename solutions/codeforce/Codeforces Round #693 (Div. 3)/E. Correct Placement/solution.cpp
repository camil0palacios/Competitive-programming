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

const int oo = 1e9 + 5;
const int Mxn = 2e5 + 5;
ii st[4*Mxn];

struct fr {
    int h, w, i;
    fr(int _h, int _w, int i): w(_w), h(_h), i(i) {}
    const bool operator<(const fr & f) { 
        if(h == f.h) return w > f.w;
        return h > f.h;
    }
};

vector<fr> a;

void build(int p, int l, int r) {
    if(l == r) {
        st[p] = {a[l].w, a[l].i};
        return;
    }
    int m = (l + r) >> 1, left = p << 1, right = left + 1;
    build(left, l, m);
    build(right, m+1, r);
    st[p] = min(st[left], st[right]);
}

ii query(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return {oo, oo};
    if(ql <= l && r <= qr) return st[p];
    int m = (l + r) >> 1, left = p << 1, right = left + 1;
    return min(query(left, l, m, ql, qr), query(right, m+1, r, ql, qr));
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n; 
        memset(st, 0, sizeof st);   
        a.clear();
        fori(i,0,n) {
            int h, w;
            cin >> h >> w;
            if(h < w) swap(h, w); 
            a.emplace_back(h, w, i);
        }
        sort(all(a));
        build(1, 0, n-1);
        int ans[n];
        fori(i,0,n) {
            ii q = {oo, oo};
            int l = 0, r = n-1, j = 0;
            while(l <= r) {
                int m = (l + r) >> 1;
                if(a[m].h < a[i].h) j = m, r = m-1;
                else l = m+1;
            }
            if(a[j].h < a[i].h) q = query(1, 0, n-1, j, n-1);
            ans[a[i].i] = q.ft >= a[i].w ? -1 : q.sd + 1; 
        }
        fori(i,0,n) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0; 
}