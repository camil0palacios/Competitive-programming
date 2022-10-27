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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll oo = 1e18;
const int Mxn = 110;
int n; ll h;
int a[Mxn];

ll pp(ll x, ll d) {
    if(d > oo - x) return oo;
    return d + x;
}

bool check(ll k) {
    ll d = 0;
    fori(i,0,n) {
        if(i+1 < n && a[i] >= a[i+1]-k+1) d = pp(a[i+1]-a[i], d);
        else d = pp(k, d);
    }
    return d >= h;
} 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> h;
        fori(i,0,n) cin >> a[i];
        ll l = 1, r = oo, ans;
        while(l <= r) {
            ll m = (l + r) >> 1;
            if(check(m)) ans = m, r = m-1;
            else l = m+1;
        }
        cout << ans << endl;
    }
    return 0; 
}