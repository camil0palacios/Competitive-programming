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
const int N = 2e5 + 5;
ll f[N], fi[N];

ll be(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int nCr(int n, int r) {
    return ((f[n]*fi[r]) % mod * fi[n-r]) % mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    f[0] = fi[0] = 1;
    fori(i,1,N) {
        f[i] = (f[i-1]*i) % mod;
        fi[i] = be(f[i], mod-2);
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(n & 1) {
            ll ans = 1;
            for(int i = 0; i < n; i += 2) ans = (ans + nCr(n, i)) % mod;
            ans = be(ans, k);
            cout << ans << endl;
        } else {
            ll eq = 0;
            for(int i = 0; i < n; i += 2) eq = (eq + nCr(n, i)) % mod;
            ll ans = 0;
            fore(i,0,k) {
                ll x = 1;
                x = (x * be(eq, i)) % mod;
                if(i < k-1) {
                    x = (x * be(2, 1ll * n * (k - i - 1)))% mod;
                }
                ans = (ans + x) % mod;
            }
            cout << ans << endl;
        }
    }
    return 0; 
}