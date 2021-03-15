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
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int oo = 1e9;
const int Mxn = 1010;
const int Mxb = 1010;
int dp[Mxn][Mxb][2];

void solve() {
    int n, b;
    string t;
    cin >> n >> b >> t;
    fori(i,0,n) fore(j,0,b) dp[i][j][0] = dp[i][j][0] = oo; 
    fore(i,0,b) dp[n-1][i][0] = 0, dp[n-1][i][1] = 2;
    forr(i,n-2,0) {
        fore(j,0,b) {
            dp[i][j][0] = dp[i+1][j][1] + 4;
            dp[i][j][1] = dp[i+1][j][1] + 2;
            if(j >= (t[i+1] == '#')) {
                dp[i][j][0] = min(dp[i][j][0], dp[i+1][j-(t[i+1] == '#')][0] + 1);
            }
            if(t[i] != '#' && j >= (t[i+1] == '#')) {
                dp[i][j][1] = min(dp[i][j][1], dp[i+1][j-(t[i+1] == '#')][0] + 3);
            }
        }
    }
    cout << dp[0][b][0] << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}