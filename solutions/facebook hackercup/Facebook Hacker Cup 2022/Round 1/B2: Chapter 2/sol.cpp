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

const int mod = 1e9 + 7;
const int N = 5e5 + 5;

void psum(vl & p, vl & p2, vl & x) {
    int n = sz(p);
    fori(i,1,n) {
        p[i] = (p[i-1] + x[i]) % mod;
        p2[i] = (p2[i-1] + (x[i]*x[i]) % mod) % mod;
    }
}

ll get_sum(int q, int j, vl & x, vl & s, vl & s2) {
    int n = sz(x);
    int l = j-1, r = j;
    if(q == x[j]) r = j+1;
    ll sum = (1ll*l*q*q % mod + s[l] - 2ll*q*s2[l] + mod) % mod;
    sum += (1ll*(n-r)*q*q % mod + (s[n-1] - s[r-1]) - 2ll*q*(s2[n-1] - s2[r-1]) + mod) % mod;
    return r;
}

void solve() {
    int n, q;
    cin >> n;
    n += 2;
    vl x(n), y(n);
    vl px(n), py(n);
    vl px2(n), py2(n);
    fori(i,1,n-1) cin >> x[i] >> y[i];
    x[n-1] = y[n-1] = 1e9 + 1;
    sort(all(x));
    sort(all(x));
    psum(px, px2, x);
    psum(py, py2, y);
    fori(i,0,n) cout << px[i] << ' '; cout << endl;
    fori(i,0,n) cout << py[i] << ' '; cout << endl;
    
    cin >> q;
    ll ans = 0;
    fori(i,0,q) {
        int xi, yi;
        cin >> xi >> yi;
        int j = lower_bound(, xi) - x.begin();
        ans = (ans + get_sum(xi, j, x, px, px2));
        j = lower_bound(all(y), yi) - y.begin();
        ans = (ans + get_sum(yi, j, y, py, py2));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}