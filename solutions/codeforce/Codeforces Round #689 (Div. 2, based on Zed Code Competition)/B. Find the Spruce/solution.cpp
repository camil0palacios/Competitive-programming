#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 505;
int n, m;
string a[Mxn];
int dp[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        fori(i,0,n) cin >> a[i];
        ll ans = 0;
        memset(dp, 0, sizeof dp);
        forr(i,n-1,0) {
            fori(j,0,m) {
                if(a[i][j] == '*') {
                    dp[i][j] = 1 + min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});
                    ans += dp[i][j]; 
                }
            }
        }
        cout << ans << endl;
    }
    return 0; 
}