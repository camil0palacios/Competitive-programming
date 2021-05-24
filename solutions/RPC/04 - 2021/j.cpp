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

const int Mxn = 1e5 + 5;
string a[Mxn];
int n, k;
int pos[Mxn][26];
int dp[26];

int go(int cur) {
    if(dp[cur] != -1) return dp[cur];
    int ans = 0;
    fori(j,0,k) {
        bool ok = 1;
        fori(i,0,n) ok &= pos[i][cur] < pos[i][j];
        if(ok) ans = max(ans, go(j) + 1);
    }
    return dp[cur] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];
    fori(i,0,n)
        fori(j,0,k) pos[i][a[i][j]-'A'] = j;
    memset(dp, -1, sizeof dp);
    int ans = 0;
    fori(i,0,k) ans = max(ans, go(i) + 1);
    cout << ans << endl;
    return 0; 
}