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

const int Mxn = 101;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int w, n;
    cin >> w >> n;
    fori(i,0,n) cin >> a[i];
    int dp[n+1][w+1];
    memset(dp, 0, sizeof dp);
    dp[n][w] = 1;
    forr(i,n-1,0) {
        fore(j,0,w) {
            dp[i][j] = dp[i+1][j];
            if(j + a[i] <= w) dp[i][j] += dp[i+1][j + a[i]];
        }
    }
    if(dp[0][0] == 1) {
        set<int> s;
        int j = 0;
        fori(i,0,n) {
            if(j + a[i] <= w && dp[i][j] == dp[i+1][j + a[i]]) {
                s.insert(i);
                j += a[i];
            }
        }
        bool ok = 0;
        fori(i,0,n)
            if(!s.count(i)) {
                if(ok) cout << ' ';
                cout << i+1;
                ok = 1;
            }
    } 
    else if(dp[0][0] > 1) cout << -1 << endl;
    else cout << 0 << endl;
    return 0; 
}