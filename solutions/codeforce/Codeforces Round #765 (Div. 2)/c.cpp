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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int oo = 1e9;
const int Mxn = 505;
int n, l, k;
int d[Mxn], a[Mxn];
int dp[Mxn][Mxn];

int go(int i, int x) {
    if(i == n) return 0;
    if(dp[i][x] != -1) return dp[i][x];
    int ans = oo;
    fore(j,0,x) {
        int nxt = i+j+1;
        if(nxt > n) break;
        ans = min(ans, go(nxt, x-j) + (d[nxt] - d[i])*a[i]);
    }
    return dp[i][x] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> l >> k;
    fori(i,0,n) cin >> d[i];
    fori(i,0,n) cin >> a[i];
    d[n] = l, a[n] = 0;    
    memset(dp, -1, sizeof dp);
    cout << go(0, k) << endl; 
    return 0; 
}