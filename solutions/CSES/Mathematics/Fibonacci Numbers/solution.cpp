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

mat mul(mat & a, mat & b) {
    int n = sz(a);
    mat c(n, vi(n));
    fori(i,0,n) fori(j,0,n) fori(k,0,n)
        c[i][j] = (1ll*c[i][j] + (1ll*a[i][k]*b[k][j]) % mod) % mod;
    return c;
}

ll be(ll n) {
    mat a = {{1, 1}, {1, 0}};
    mat ans = {{1,0},{0,1}};
    while(n) {
        if(n & 1) ans = mul(ans, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ans[0][0] % mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    if(n == 0) cout << 0 << endl;
    else cout << be(n-1) << endl;
    return 0; 
}