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

const int Mxn = 5e6 + 5;
int n, a, b;
int dp[Mxn][2];

int go(int f, int x) {
    auto & ans = dp[f][x];
    if(ans == -1) {
        ans = f;
        if(a+f <= n) ans = max(ans, go(f+a, x));
        if(b+f <= n) ans = max(ans, go(f+b, x));
        if(x) ans = max(ans, go(f/2, x^1));  
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    cin >> n >> a >> b;
    // memset(dp, -1, sizeof dp);
    // cout << go(0,1) << endl;
    forr(i,n,0) {
        int & ans = dp[i][0];
        ans = i;
        if(a+i <= n) ans = max(ans, dp[a+i][0]);
        if(b+i <= n) ans = max(ans, dp[b+i][0]);
    }
    forr(i,n,0) {
        int & ans = dp[i][1];
        ans = i;
        if(a+i <= n) ans = max(ans, dp[a+i][1]);
        if(b+i <= n) ans = max(ans, dp[b+i][1]);
        ans = max(ans, dp[i/2][0]);
    }
    cout << dp[0][1] << endl;
    return 0;
}