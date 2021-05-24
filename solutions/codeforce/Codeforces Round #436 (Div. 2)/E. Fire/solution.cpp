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

const int Mxn = 110;
const int Mxd = 20;
struct item { int t, d, p, i; };
int n;
item a[Mxn];
int dp[Mxn][Mxn*Mxd];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fori(i,0,n) cin >> a[i].t >> a[i].d >> a[i].p, a[i].i = i;
    sort(a, a+n, [](item & x, item & y) {
        if(x.d == y.d) return x.p > y.p;
        return x.d < y.d;
    });
    int T = 0;
    fori(i,0,n) T += a[i].t;
    forr(i,n-1,0) {
        fore(t,0,T) {
            dp[i][t] = dp[i+1][t];
            if(t+a[i].t < a[i].d && t+a[i].t <= T)
                dp[i][t] = max(dp[i][t], dp[i+1][t+a[i].t] + a[i].p);
        }
    }
    cout << dp[0][0] << endl;
    vi res;
    int t = 0;
    fori(i,0,n) {
        int cur = 0;
        if(t+a[i].t < a[i].d && t+a[i].t <= T && dp[i][t] == dp[i+1][t+a[i].t] + a[i].p) {
            res.eb(a[i].i+1);
            t += a[i].t; 
        }
    }
    cout << sz(res) << endl;
    for(auto & i : res) cout << i << ' ';
    cout << endl;
    return 0;
}