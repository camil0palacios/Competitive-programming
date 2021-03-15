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
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int ll mod = 1e9 + 7;
const int Mxn = 1e6 + 6;
ll f[Mxn], invf[Mxn];
int a, b, n;

bool check(int s) {
    unordered_set<int> x;
    while(s) { x.insert(s % 10); s /= 10; }
    if(sz(x) == 1) return x.count(a) || x.count(b);
    return sz(x) == 2 && x.count(a) && x.count(b);
}

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}

ll aCb(int a, int b) {
    return ((f[a]*invf[b]%mod)*invf[a-b])%mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b >> n;
    f[0] = invf[0] = 1;
    fore(i,1,n) {
        f[i] = (f[i-1]*i)%mod;
        invf[i] = be(f[i], mod-2);
    }
    ll ans = 0;
    fore(i,0,n) {
        int s = i*a + (n-i)*b;
        if(check(s)) ans = (ans + aCb(n, i))%mod;
    }
    cout << ans << endl;
    return 0; 
}