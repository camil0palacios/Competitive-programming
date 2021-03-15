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
typedef vector<vi> mat;

const int mod = 1e9 + 7;
ll f[7];

mat mul(mat & a, mat & b) {
    int n = sz(a);
    mat c(n, vi(n));
    fori(i,0,n) fori(j,0,n) fori(k,0,n) 
        c[i][j] = (1ll*c[i][j] + 1ll*a[i][k]*b[k][j] % mod) % mod;
    return c;
}

ll be(ll n) {
    mat a(6, vi(6));
    mat ans(6, vi(6));
    fori(i,0,6) a[0][i] = ans[i][i] = 1;
    fori(i,1,6) a[i][i-1] = 1;
    while(n > 0) {
        if(n & 1) ans = mul(ans, a);
        a = mul(a, a);
        n >>= 1;
    }
    ll res = 0;
    fori(i,0,6) res = (res + ans[0][i]*f[6-i] % mod) % mod;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    f[0] = 1;
    fore(i,1,6)
        fore(j,1,6)
            if(j <= i) f[i] = (f[i] + f[i-j]) % mod;
    ll n;
    cin >> n;
    if(n <= 6) cout << f[n] << endl;
    else cout << be(n-6) << endl;
    return 0; 
}