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

int R, G, B;
vi r(205), g(205), b(205);
ll dp[205][205][205];

ll go(int i, int j, int k) {
    if(i == R && j == G && k == B) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    ll ans = 0;
    if(i < R && j < G) ans = go(i+1, j+1, k) + r[i]*g[j];
    if(i < R && k < B) ans = max(ans, go(i+1, j, k+1) + r[i]*b[k]);
    if(j < G && k < B) ans = max(ans, go(i, j+1, k+1) + g[j]*b[k]);
    return dp[i][j][k] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> G >> B;
    fori(i,0,R) cin >> r[i];
    fori(i,0,G) cin >> g[i];
    fori(i,0,B) cin >> b[i];
    // dp[i][j][k] = max(dp[i+1][j+1][k] + r[i]*g[i], dp[i+1][j][k+1] + r[i]*b[k], dp[i][j+1][k+1] + g[j]*b[k])
    memset(dp, -1, sizeof dp);
    sort(all(r), greater<int>());
    sort(all(g), greater<int>());
    sort(all(b), greater<int>());
    cout << go(0,0,0) << endl;
    return 0; 
}