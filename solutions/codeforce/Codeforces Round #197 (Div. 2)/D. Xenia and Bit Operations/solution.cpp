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

const int Mxn = 1 << 18;
int st[4*Mxn], op[4*Mxn];
int a[Mxn];

void build(int p, int l, int r) {
    if(l == r) {
        st[p] = a[l];
        op[p] = 1;
    } else { 
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        build(left, l, mid);
        build(right, mid+1, r);
        op[p] = op[left]^1;
        if(op[p]) st[p] = st[left] ^ st[right];
        else st[p] = st[left] | st[right];
    }
}
void update(int p, int l, int r, int idx, int val) {
    if(idx < l || r < idx) return;
    if(l == r) {
        st[p] = val;
    } else {
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        update(left, l, mid, idx, val);
        update(right, mid+1, r, idx, val);
        if(op[p]) st[p] = st[left] ^ st[right];
        else st[p] = st[left] | st[right];        
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    fore(i,1,1 << n) cin >> a[i];
    build(1, 1, 1 << n);
    fori(i,0,q) {
        int p, b;
        cin >> p >> b;
        update(1, 1, 1 << n, p, b);
        cout << st[1] << endl;
    }
    return 0; 
}