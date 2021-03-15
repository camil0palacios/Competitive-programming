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
typedef vector<vector<ll>> mat;

const int mod = 1e9 + 7;

mat mul(mat & a, mat & b) {
    int n = sz(a);
    mat c(n, vector<ll>(n));
    fori(i,0,n) fori(j,0,n) fori(k,0,n) 
        c[i][j] = (c[i][j] + (a[i][k]*b[k][j]) % mod) % mod; 
    return c;
}

ll be(mat & a, int k) {
    int n = sz(a);
    mat ans(n, vector<ll>(n));
    fori(i,0,n) ans[i][i] = 1;
    while(k) {
        if(k & 1) ans = mul(ans, a);
        a = mul(a, a);
        k >>= 1;
    }
    return ans[0][n-1] % mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    mat a(n, vector<ll>(n));
    fori(i,0,m) {
        int u, v; 
        cin >> u >> v;
        u--, v--;
        a[u][v]++;
    }
    cout << be(a, k) << endl;
    return 0; 
}