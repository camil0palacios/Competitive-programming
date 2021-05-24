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

const int Mxn = 1010;
const int Mxc = 1e5 + 5;
int a[Mxn];
int dp[Mxn][Mxc];

void cal(int n, int w) {
    dp[n][0] = 1;
    forr(i,n-1,0) {
        fore(j,0,w) {
            dp[i][j] |= dp[i+1][j];
            if(a[i] <= j) dp[i][j] |= dp[i+1][j-a[i]];
        }
    }  
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, c;
    cin >> n >> c;
    fori(i,0,n) cin >> a[i];
    sort(a, a+n);
    cal(n, c);
    int ans = 1e9;
    forr(x,c,0) {
        if(dp[0][x]) {
            int w = c - x, j = x;
            bool ok = 1;
            fori(i,0,n) {
                if(dp[i][j] == dp[i+1][j] && a[i] > w);
                else if(dp[i][j] == dp[i+1][j-a[i]]) j -= a[i];
                else { ok = 0; break; }
            }
            if(ok) ans = min(ans, x); 
        }
    }
    cout << ans << endl;
    return 0; 
}