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
int a[Mxn];
vi b;
char q[Mxn];
int L[Mxn], R[Mxn];

ll bit[Mxn];
int get_id(int x) {
    return lower_bound(all(b), x) - b.begin();
}
void add(int i, int val) {
    i = get_id(i) + 1;
    for(; i < Mxn; i += i & -i) bit[i] += val;
}
ll sum(int i) {
    ll ans = 0;
    for(; i; i -= i & -i) ans += bit[i];
    return ans;
}
ll query(int l, int r) {
    l = get_id(l) + 1;
    r = get_id(r) + 1;
    return sum(r) - sum(l-1);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) {
        cin >> a[i];
        b.eb(a[i]);
    }
    fori(i,0,m) {
        cin >> q[i] >> L[i] >> R[i];
        if(q[i] == '?') b.eb(L[i]);
        b.eb(R[i]);
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    fori(i,0,n) add(a[i], 1);
    fori(i,0,m) {
        if(q[i] == '!') {
            int k = L[i]-1, x = R[i];
            add(a[k], -1);
            a[k] = x;
            add(a[k], 1);
        } else {
            cout << query(L[i], R[i]) << endl;
        }
    }
    return 0;
}