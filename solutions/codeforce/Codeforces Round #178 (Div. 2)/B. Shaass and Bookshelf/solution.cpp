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
const int Mxn = 105;
int t[Mxn], w[Mxn];
int dp[Mxn][2*Mxn][2*Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> t[i] >> w[i];
    int s = 0;
    fori(i,0,n) s += t[i];
    fore(i,0,s) fore(j,0,s) dp[n][i][j] = j >= i ? j : oo;
    forr(i,n-1,0) {
        fore(x,0,s) {
            fore(y,0,s) {
                dp[i][x][y] = oo;
                int & ans = dp[i][x][y];
                if(y+t[i] <= s) ans = dp[i+1][x][y+t[i]];
                if(x+w[i] <= s) ans = min(ans, dp[i+1][x+w[i]][y]);
            }
        }
    }
    cout << dp[0][0][0] << endl;
    return 0;
}