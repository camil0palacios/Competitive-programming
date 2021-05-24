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
const int Mxm = 2e5 + 5;
ll dp[Mxm][10];

void add(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

void cal() {
    fore(i,0,9) dp[0][i] = 1;
    fori(i,1,Mxm) {
        fore(x,0,9) {
            ll & ans = dp[i][x];
            if(x == 9) ans = (dp[i-1][1] + dp[i-1][0]) % mod; 
            else ans = dp[i-1][x+1];
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int t;
    cin >> t;
    while(t--) {
        string n; int m;
        cin >> n >> m;
        ll ans = 0;
        fori(i,0,sz(n)) {
            add(ans, dp[m][n[i]-'0']);
        }
        cout << ans << endl;
    }
    return 0; 
}