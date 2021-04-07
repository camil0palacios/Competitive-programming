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
const int Mxn = 2010;
int n, k;
ll dp[Mxn][Mxn][2];

ll go(int i, int j, bool d) {
    if(i == 0 || i == n+1 || j == 1) return 1;
    if(dp[i][j][d] != -1) return dp[i][j][d];
    ll ans = 0;
    if(d) {
        if(i <= n) ans = (ans + go(i+1, j, d)) % mod; 
        if(i >= 1) ans = (ans + go(i-1, j-1, d^1)) % mod;
    }
    if(!d) {
        if(i >= 1) ans = (ans + go(i-1, j, d)) % mod;
        if(i <= n) ans = (ans + go(i+1, j-1, 1)) % mod;
    }
    return dp[i][j][d] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        memset(dp, -1, sizeof dp);
        cout << go(1, k, 1) << endl;
    }
    return 0; 
}