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

const ll oo = 1e18;
const int Mxn = 1e4 + 5;
const int Mxk = 105;
ll dp[Mxn][Mxk];
int a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i,0,n) {
            int x, y;
            cin >> a[i] >> x >> y;
            b[i] = max(x, y);
        }
        fore(i,0,n) fore(j,0,k) dp[i][j] = -oo;
        dp[n][k] = 0;
        forr(i,n-1,0) {
            fore(j,0,k) {
                dp[i][j] = max(dp[i+1][min(k, j + a[i])], dp[i+1][j] + b[i]);
            }
        } 
        if(dp[0][0] > 0) cout << dp[0][0] << endl;
        else cout << "NO SOLUTION" << endl;
    }
    return 0; 
}