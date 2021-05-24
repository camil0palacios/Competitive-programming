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
const int Mxn = 4040;
int dp[Mxn][Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    fore(i,0,n) fore(l,1,n) dp[i][l] = -oo;
    dp[n][1] = 0;
    forr(i,n-1,0) {
        fore(l,1,n) {
            int & ans = dp[i][l];
            ans = dp[i+1][l+1];
            if(l == a || l == b || l == c) ans = max(ans, dp[i+1][1] + 1);
        }
    }
    cout << dp[0][1] << endl;
    return 0; 
}