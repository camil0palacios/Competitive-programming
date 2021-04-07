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

const int mod = 100000000;
const int Mxn = 110;
ll dp[Mxn][Mxn][2];

void add(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    fore(x,0,n1) {
        fore(y,0,n2) {
            if(x == 0 && y == 0) { dp[x][y][0] = dp[x][y][1] = 1; continue; }
            fore(j,1,min(k1,x)) add(dp[x][y][0], dp[x-j][y][1]);
            fore(j,1,min(k2,y)) add(dp[x][y][1], dp[x][y-j][0]);
        }
    }
    ll ans = (dp[n1][n2][0] + dp[n1][n2][1]) % mod;
    cout << ans << endl;
    return 0; 
}