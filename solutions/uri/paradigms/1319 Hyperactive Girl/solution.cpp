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

const int oo = 1e9;
const int mod = 1e8;
const int Mxn = 110;
int n, m;
ii a[Mxn];
ll dp[Mxn][Mxn];

void add(ll & x, ll y) {
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
}

ll go(int idx, int lst) {
    if(a[idx].sd == m) return 1;
    ll & ans = dp[idx][lst];
    if(ans == -1) {
        ans = 0;
        fori(i,0,n)
            if(a[lst].sd < a[i].ft && a[i].ft <= a[idx].sd && a[idx].sd < a[i].sd)
                add(ans, go(i, idx));
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> m >> n, n || m) {
        fori(i,0,n) cin >> a[i].ft >> a[i].sd;
        fore(i,0,n) fore(j,0,n) dp[i][j] = -1;
        a[n].ft = a[n].sd = 0;
        sort(a, a+n);
        ll ans = 0;
        fori(i,0,n)
            if(a[i].ft == 0)
                add(ans, go(i,n));
        cout << ans << endl;
    }
    return 0;
}