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

const int oo = 1e5;
const int Mxn = 110;
int dp[Mxn][Mxn][Mxn];

void solve() {
    string a, b;
    int k; 
    cin >> a >> b >> k;
    int n = sz(a), m = sz(b);
    fore(i,0,n) fore(j,0,m) fore(x,0,k) dp[i][j][x] = -oo;
    fore(i,0,n) fore(j,0,m) dp[i][j][0] = 0;
    forr(i,n-1,0) {
        forr(j,m-1,0) {
            fore(x,1,k) {
                int & ans = dp[i][j][x];
                if(a[i] == b[j]) ans = max(ans, dp[i+1][j+1][x-1] + a[i]);
                ans = max(ans, max(dp[i+1][j][x], dp[i][j+1][x]));
            }
        }
    }
    cout << (dp[0][0][k] > 0 ? dp[0][0][k] : 0) << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}