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
const int Mxc = 55;
int bit[2*Mxn];
set<int, greater<int>> col[Mxc];

void upd(int i, int val) {
    for(; i < 2*Mxn; i += i & -i) bit[i] += val;
}
int sum(int i) {
    int ans = 0;
    for(; i; i -= i & -i) ans += bit[i];
    return ans;
}
int qry(int l, int r) {
    return sum(r) - sum(l-1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    forr(i,n,1) {
        int a; cin >> a;
        col[a].insert(i);
        upd(i, 1);
    }
    int p = n;
    fori(i,0,q) {
        int t; cin >> t;
        int pos = *col[t].begin();
        col[t].erase(col[t].begin());
        cout << qry(pos, 2*Mxn-1) << ' ';
        upd(pos, -1);
        col[t].insert(++p);
        upd(p, 1);
    }
    return 0; 
}