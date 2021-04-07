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
const int oo = 1e9;
string s;
int n, x, y;
int dp[Mxn][2];

void solve() {
    cin >> x >> y >> s;
    n = sz(s);
    fore(i,0,n) dp[i][0] = dp[i][1] = oo;
    dp[n][0] = dp[n][1] = 0;
    forr(i,n-1,0) {
        if(s[i] == '?') {
            dp[i][0] = min(dp[i+1][0], dp[i+1][1] + x);
            dp[i][1] = min(dp[i+1][1], dp[i+1][0] + y);
        } else {
            int j = s[i] == 'C' ? 0 : 1;
            int a, b;
            if(j == 0) a = 0, b = y;
            else a = x, b = 0;
            dp[i][0] = dp[i+1][j] + a;
            dp[i][1] = dp[i+1][j] + b;
        }     
    }
    cout << min(dp[0][0], dp[0][1]) << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}