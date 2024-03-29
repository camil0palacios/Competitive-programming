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

const int Mxn = 3030;
int a[Mxn], b[Mxn], c[Mxn];
ll dp[Mxn][2];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    cin >> n;
    fori(i,0,n) cin >> a[i];
    fori(i,0,n) cin >> b[i];
    fori(i,0,n) cin >> c[i];
    memset(dp, 0, sizeof dp);
    dp[n-1][0] = a[n-1];
    dp[n-1][1] = b[n-1];
    forr(i,n-2,0) {
        dp[i][0] = max(dp[i+1][1] + a[i], dp[i+1][0] + b[i]);
        dp[i][1] = max(dp[i+1][0] + c[i], dp[i+1][1] + b[i]);
    }
    cout << dp[0][0] << endl;
    return 0;
}