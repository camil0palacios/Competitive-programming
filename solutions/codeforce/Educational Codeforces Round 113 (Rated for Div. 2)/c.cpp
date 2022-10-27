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

const int mod = 998244353;
const int Mxn = 2e5 + 5;
int n;
int a[Mxn];
ll f[Mxn];

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    f[0] = 1;
    fori(i,1,Mxn) {
        f[i] = (f[i-1] * i) % mod;
    }
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        map<int, int> m;
        fori(i,0,n) cin >> a[i], m[a[i]]++;
        sort(a, a+n);
        int mx = a[n-1];
        if(m[mx] > 1) cout << f[n] << endl;
        else if(m[mx-1] == 0) cout << 0 << endl;
        else {
            int k = m[mx-1];
            ll ans = (f[n] - (f[n]*be(k+1, mod-2)) % mod + mod) % mod;
            cout << ans << endl;
        }

    }
    return 0; 
}