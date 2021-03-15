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
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

ll cube(ll x) {
    return x*x*x;
}

ll bs(ll x) {
    ll l = 1, r = 10000 + 5;
    while(l <= r) {
        ll m = (l + r) >> 1;
        if(cube(m) <= x) l = m+1;
        else r = m-1;
    }
    return l > 1 && cube(l-1) == x;
}

void solve() {
    ll x;
    cin >> x;
    for(ll i = 1; i*i*i <= x; i++) {
        if(bs(x - i*i*i)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}