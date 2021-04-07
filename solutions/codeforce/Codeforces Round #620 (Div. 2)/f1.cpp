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

const int Mxn = 55;
const int Mxm = 2e4 + 5;
int n, m, k;
int s[Mxn][Mxm];
int lmx[Mxn][Mxm], rmx[Mxn][Mxm];
int dp[Mxn][Mxm];

int inter(int i, int j, int d) {
    int l = max(i, j), r = min(i+k-1, j+k-1);
    return s[d][r] - s[d][l-1];
}

int ps(int d, int i) {
    return s[d][i+k-1] - s[d][i-1];
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    fore(i,1,n) fore(j,1,m) cin >> s[i][j];
    fore(i,1,n) fore(j,1,m) s[i][j] += s[i][j-1];
    fore(d,1,n) {
        fore(l,1,m-k+1) {
            int val = ps(d,l) + ps(d+1, l);
            int & ans = dp[d][l];
            if(d == 1) {
                ans = val;
                continue;
            } 
            fore(i,max(1,l-k+1),min(m,l+k-1)) {
                ans = max(ans, dp[d-1][i] + val - inter(i, l, d));
            }
            if(l-k >= 1)
                ans = max(ans, lmx[d-1][l-k] + val);
            if(l+k <= m-k+1)
                ans = max(ans, rmx[d-1][l+k] + val);
        }
        fore(i,1,m-k+1) 
            lmx[d][i] = max(lmx[d][i-1], dp[d][i]);
        forr(i,m-k+1,1) 
            rmx[d][i] = max(rmx[d][i+1], dp[d][i]);
    }
    int ans = 0;
    fore(i,1,m-k+1) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0; 
}