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

const int Mxn = 1e6 + 5;
int h[Mxn];

int st[4*Mxn];
void update(int p, int l, int r, int idx, int val) {
    if(idx < l || r < idx) return;
    if(l == r) st[p] = val;
    else {
        int m = (l + r) >> 1, left = p << 1, right = left + 1;
        update(left, l, m, idx, val);
        update(right, m+1, r, idx, val);
        st[p] = max(st[left], st[right]);
    }
}
int find(int p, int l, int r, int val) {
    if(l == r) return l;
    int m = (l + r) >> 1, left = p << 1, right = left + 1;
    if(val <= st[left]) return find(left, l, m, val);
    return find(right, m+1, r, val); 
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) {
        cin >> h[i];
        update(1,0,n-1,i,h[i]);
    }
    fori(i,0,m) {
        int r; cin >> r;
        if(r <= st[1]) {
            int idx = find(1,0,n-1,r);
            cout << idx+1 << ' ';
            update(1,0,n-1,idx,h[idx]-r);
            h[idx] -= r;
        } else cout << 0 << ' ';
    }
    return 0; 
}