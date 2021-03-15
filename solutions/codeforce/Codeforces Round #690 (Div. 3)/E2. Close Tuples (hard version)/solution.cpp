#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const int Mxn = 2e5 + 5;
ll f[Mxn], invf[Mxn];

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void cal() {
    f[0] = invf[0] = 1;
    for(int i = 1; i < Mxn; i++) {
        f[i] = (f[i-1]*i) % mod; 
        invf[i] = be(f[i], mod-2);
    }
}

int nCr(int n, int r) {
    // n! / (r! (n - r)!)
    return (f[n] * invf[r] % mod * invf[n - r]) % mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n);
        fori(i,0,n) cin >> a[i];
        sort(all(a));
        int r = 0;
        ll ans = 0;
        for(int i = 0; i + m - 1 < n; i++) {
            while(r < n && a[r] - a[i] <= k) r++;
            r--;
            if(r - i >= m - 1)
                ans = (ans + nCr(r - i, m - 1)) % mod;
        }
        cout << ans << endl;
    }
    return 0; 
}