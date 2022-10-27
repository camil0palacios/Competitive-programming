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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int oo = 1e9;
const int Mxn = 110;
const int Mxs = Mxn*Mxn;
int n;
int a[Mxn], b[Mxn];
ll dp[Mxn][Mxs];
int s[Mxn][2];

ll go(int i, int x) {
    if(i == n+1) return 0;
    ll & ans = dp[i][x];
    if(ans == -1) {
        int d = s[i-1][0] - x;
        int y = s[i-1][1] + d;
        ans = min(
            go(i+1, x+a[i]) + 1ll*y*b[i] + 1ll*x*a[i], 
            go(i+1, x+b[i]) + 1ll*y*a[i] + 1ll*x*b[i]
        );
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fore(i,1,n) cin >> a[i];
        fore(i,1,n) cin >> b[i];
        fore(i,1,n) {
            s[i][0] = s[i-1][0] + a[i];
            s[i][1] = s[i-1][1] + b[i];
        }
        ll ans = 0;
        fore(i,1,n) ans += a[i]*a[i];
        fore(i,1,n) ans += b[i]*b[i];
        ans *= (n-1);
        memset(dp, -1, sizeof dp);
        ans += 2ll*go(1, 0);
        cout << ans << endl;
    }
    return 0; 
}