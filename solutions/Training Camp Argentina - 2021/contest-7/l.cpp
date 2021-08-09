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

const int mod = 1e9 + 7;
const int Mxl = 3010;
const int Mxn = 110;
int n, l;
int a[Mxn], b[Mxn];
ll dp[Mxn][Mxl][2];

ll go(int i, int len, bool t) {
    if(len == l) return 1;
    if(dp[i][len][t] != -1) return dp[i][len][t];
    ll ans = 0;
    ii p1 = {a[i], b[i]};
    if(t) swap(p1.ft, p1.sd);
    fori(j,0,n) {
        if(i == j) continue;
        ii p2 = {a[j], b[j]};
        int to = a[j] != b[j] ? 2 : 1;
        fori(x,0,to) {
            if(x) swap(p2.ft, p2.sd);
            if(p1.sd == p2.ft && len + p2.ft <= l) {
                ans = (ans + go(j, len + p2.ft, x)) % mod;
            }        
        }
    }
    return dp[i][len][t] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> l;
    fori(i,0,n) cin >> a[i] >> b[i];
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    fori(i,0,n) {
        ans = (ans + go(i, a[i], 0)) % mod;
        if(a[i] != b[i]) ans = (ans + go(i, b[i], 1)) % mod;
    }
    cout << ans << endl;   
    return 0; 
}