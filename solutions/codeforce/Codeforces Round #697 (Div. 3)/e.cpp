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

const int mod = 1e9 + 7;
const int Mxn = 1010;
int a[Mxn];
int dp1[Mxn][Mxn];
ll dp2[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i,0,n) cin >> a[i];
        fore(i,0,n) fore(j,0,k) dp1[i][j] = dp2[i][j] = 0;
        dp2[n][k] = 1;
        forr(i,n-1,0) {
            fore(j,0,k) {
                dp1[i][j] = dp1[i+1][j];
                if(j < k) dp1[i][j] = max(dp1[i][j], dp1[i+1][j+1] + a[i]);
                if(dp1[i][j] == dp1[i+1][j]) {
                    dp2[i][j] += dp2[i+1][j];
                    dp2[i][j] %= mod;
                }
                if(j < k && dp1[i][j] == dp1[i+1][j+1] + a[i]) {
                    dp2[i][j] += dp2[i+1][j+1];
                    dp2[i][j] %= mod;
                }
            }  
        }
        cout << dp2[0][0] << endl;
    }
    return 0; 
}