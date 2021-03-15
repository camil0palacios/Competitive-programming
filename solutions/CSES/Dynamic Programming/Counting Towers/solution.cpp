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

const ll mod = 1e9 + 7;
const int Mxn = 1e6 + 5;
int n;
ll dp[Mxn][10];

void add(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    dp[0][0] = 1;
    fori(i,1,Mxn) {
        fore(j,0,5) {
            if(j <= 3) {
                fore(k,0,4) add(dp[i][j], dp[i-1][k]);
            }
            if(j == 4 || j == 5) {
                add(dp[i][j], dp[i-1][0]);
                add(dp[i][j], dp[i-1][4]);
                add(dp[i][j], dp[i-1][5]);
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = (dp[n][0] + dp[n][4]) % mod;
        cout << ans << endl;
    }
    return 0; 
}