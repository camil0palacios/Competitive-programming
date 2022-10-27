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
ll bit[Mxn];

void upd(int i, int x) {
    for(; i < Mxn; i += i & -i) bit[i] += x;
}
ll sum(int i)  {
    ll ans = 0;
    for(; i; i -= i & -i) ans += bit[i];
    return ans;
}
ll qry(int l, int r) {
    return sum(r) - sum(l-1);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    fore(i,1,n) {
        int e; cin >> e;
        upd(i, e);
    }
    fori(i,0,q) {
        char q;
        cin >> q;
        if(q == 'q') {
            int l, r;
            cin >> l >> r;
            cout << qry(l, r) << endl; 
        } else {
            int u, d;
            cin >> u >> d;
            upd(u, d);
        }

    }
    return 0; 
}