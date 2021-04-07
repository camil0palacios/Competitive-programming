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
const int Mxn = 55;
int n, k;
string s;
int x, y;
int dp[Mxn][Mxn];

int go(int i, int lst) {
    if(i - lst > k) return oo;
    if(i == y) return y - lst <= k ? 0 : oo;
    if(dp[i][lst] != -1) return dp[i][lst];
    int ans = go(i+1, lst);
    if(s[i] == '*') ans = min(ans, go(i+1, i) + 1);
    return dp[i][lst] = ans;
}

void solve() {
    cin >> n >> k >> s;
    fori(i,0,n) if(s[i] == '*') {
        x = i;
        break;
    }
    forr(i,n-1,0) if(s[i] == '*') {
        y = i;
        break;
    }
    if(x == y) cout << 1 << endl;
    else {
        memset(dp, -1, sizeof dp);
        cout << go(x+1,x) + 2 << endl;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}