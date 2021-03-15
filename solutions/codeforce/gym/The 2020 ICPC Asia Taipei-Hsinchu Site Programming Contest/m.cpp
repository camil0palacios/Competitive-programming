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

int m, n; 
int row, col;
int dp[6][1 << 3][1 << 3];

int go(int i, int r, int c) {
    if(i == 5) return r == row && c == col;
    if(dp[i][r][c] != -1) return dp[i][r][c];
    int ans = go(i+1, r, c) + go(i+1, r | (1 << ((i-1)/2)), c | (1 << ((i-1)%2)));
    return dp[i][r][c] = ans;
}

void solve() {
    cin >> m >> n;
    row = col = 0;
    fori(i,0,m) {
        int x; cin >> x;
        row |= 1 << x; 
    }
    fori(i,0,n) {
        int x; cin >> x;
        col |= 1 << x;
    }
    // memset(dp, -1, sizeof dp);
    // cout << go(1,0,0) << endl;
    memset(dp, 0, sizeof dp);
    dp[5][row][col] = 1;
    forr(i,4,1)
        fori(r,0,1 << 2)
            fori(c,0,1 << 2) 
                dp[i][r][c] = dp[i+1][r][c] + dp[i+1][r | (1 << ((i-1)/2))][c | (1 << ((i-1)%2))];
    cout << dp[1][0][0] << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}