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

const ll oo = 1e12;
const int Mxn = 505;
ll a[Mxn][Mxn];
ll dp[Mxn][Mxn][15];
int r, c, n;

bool is_pass(int x, int y) {
    return x-1 >= 0 && x+1 < r && y-1 >= 0 && y+1 < c && 
        a[x-1][y] != -1 && a[x+1][y] != -1 && 
        a[x][y-1] != -1 && a[x][y+1] != -1 &&
        a[x][y] > a[x][y-1] && a[x][y] > a[x][y+1] &&
        a[x][y] < a[x-1][y] && a[x][y] < a[x+1][y];
}

ll go(int x, int y, int p) {
    if(y == c) return p == n ? 0 : oo;
    auto & ans = dp[x][y][p];
    if(ans == -1) {
        ans = oo;
        int np = p + is_pass(x, y);
        if(np <= n) {
            if(a[x][y+1] != -1) ans = min(ans, go(x, y+1, np) + a[x][y]);
            if(x-1 >= 0 && a[x-1][y+1] != -1) ans = min(ans, go(x-1, y+1, np) + a[x][y]);
            if(x+1 < r && a[x+1][y+1] != -1) ans = min(ans, go(x+1, y+1, np) + a[x][y]);
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> r >> c >> n;
    fori(i,0,r) fori(j,0,c) cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    ll ans = oo;
    fori(i,0,r)
        if(a[i][0] != -1) ans = min(ans, go(i,0,0));
    if(ans < oo) cout << ans << endl;
    else cout << "impossible" << endl; 
    return 0;
}