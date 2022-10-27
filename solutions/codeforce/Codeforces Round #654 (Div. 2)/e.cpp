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

const int Mxn = 2002;
int n, p;
int a[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> p;
    fori(i,0,n) cin >> a[i];
    sort(a, a+n);
    int top = a[n-1], bot = a[0];
    int dp[n+1][top+1];
    memset(dp, 0, sizeof dp);
    fore(i,bot,top) dp[n][i] = 1 % p;
    forr(i,n-1,0) {
        fore(x,bot,top) {
            int j = upper_bound(a, a+n, x) - a;
            int opt = j - i;
            if(opt <= 0) dp[i][x] = 0;
            else dp[i][x] = (opt*dp[i+1][min(x+1, top)]) % p;
        }
    }
    vi ans;
    fore(x,a[0],a[n-1]) if(dp[0][x] != 0) ans.eb(x); 
    cout << sz(ans) << endl;
    for(auto x : ans) cout << x << ' ';
    cout << endl;  
    return 0; 
}