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

const ll mod = 1e9+7;
const int Mxn = 1e5 + 5;
int a[Mxn];

ll be(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y&1) ans = (ans*x)%mod;
        x = (x*x)%mod;
        y >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    ll s = 0; int mx = 0;
    fori(i,0,n) cin >> a[i], s += a[i], mx = max(mx, a[i]);
    map<ll, ll> m;
    fori(i,0,n) {
        a[i] = mx - a[i];
        m[a[i]]++;
    }
    s -= mx;
    int i = 0;
    while(m[i] % x == 0) {
        m[i+1] += m[i] / x;
        i++;
    }
    s += min(i, mx);
    cout << be(x, s) << endl;
    return 0; 
}