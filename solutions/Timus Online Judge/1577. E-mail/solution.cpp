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
typedef vector<ii> vii;

const int mod = 1e9 + 7;
const int Mxs = 2005;
int dp1[Mxs][Mxs];
ll dp2[Mxs][Mxs];
string s, t;
int n, m;

void add(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> t;
    n = sz(s), m = sz(t);
    fore(i,0,m) dp1[n][i] = m-i, dp2[n][i] = 1;
    fore(i,0,n) dp1[i][m] = n-i, dp2[i][m] = 1;
    forr(i,n-1,0) {
        forr(j,m-1,0) {
            dp1[i][j] = s[i] == t[j] ? dp1[i+1][j+1] + 1: min(dp1[i+1][j], dp1[i][j+1]) + 1;
            if(s[i] == t[j]) dp2[i][j] = dp2[i+1][j+1];
            else if(dp1[i+1][j] < dp1[i][j+1]) dp2[i][j] = dp2[i+1][j];
            else if(dp1[i+1][j] > dp1[i][j+1]) dp2[i][j] = dp2[i][j+1];
            else {
                int x = (dp2[i+1][j] + dp2[i][j+1]) % mod;
                add(dp2[i][j], x);
            }
        }
    }
    cout << dp2[0][0] << endl;
    return 0;
}