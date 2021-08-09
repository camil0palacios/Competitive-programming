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

const int Mxn = 50050;
const int Mxm = 25;
int n, m;
int dp[Mxn][Mxm];

int go(int a, int b) {
    if(a == 0 || b == 0) return a == 0 ? 0 : 1e9;
    if(dp[a][b] != -1) return dp[a][b];
    int ans = 1e9;
    fore(i,1,a)
        ans = min(ans, max(go(a-i, b), go(i-1, b-1)) + 1);
    return dp[a][b] = ans;
} 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    int ans = go(n, m);
    vi res;
    fore(i,1,n) {
        if(ans == max(go(n-i, m), go(i-1, m-1)) + 1)
            res.eb(i);
    }
    cout << ans << ' ' << res[0];
    if(sz(res) > 1) cout << "-" << res.back();
    cout << endl;
    return 0; 
}