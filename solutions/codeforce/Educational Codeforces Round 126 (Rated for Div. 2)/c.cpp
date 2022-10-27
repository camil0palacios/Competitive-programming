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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll oo = 1e18;
const int N = 3e5 + 5;
int n;
ll h[N], tmp[N];

bool check(ll x, int mx) {
    ll ev = x/2, odd = x - ev;
    fori(i,0,n) {
        ll p = (mx - h[i]) / 2;
        if(ev) {
            ll mn = min(ev, p);
            ev -= mn;
            tmp[i] = mx - (2*mn + h[i]);
        } else tmp[i] = mx - h[i];
    }
    fori(i,0,n) {
        if(tmp[i] <= odd) odd -= tmp[i];
        else return 0;
    }
    return 1;
}

ll solve(ll mx) {
    ll l = 0, r = oo, ans;
    while(l <= r) {
        ll m = (l + r) >> 1;
        if(check(m, mx)) ans = m, r = m-1;
        else l = m+1;
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fori(i,0,n) cin >> h[i];
        sort(h, h+n);
        ll ans = oo;
        fori(i,0,20) {
            ans = min(ans, solve(h[n-1]+i));
        }
        cout << ans << endl;
    }
    return 0; 
}