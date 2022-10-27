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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll oo = 1e12;
const int N = 1010;
const int P = 110;
int n, p;
ll x[N][P];
ll dp[N][P];

ll getMin(int i, int j, int k) {
    ll l = abs(x[i-1][j] - x[i][0]) + (x[i][p-1] - x[i][0]) + (x[i][p-1] - x[i][k]);
    ll r = abs(x[i-1][j] - x[i][p-1]) + (x[i][p-1] - x[i][0]) + (x[i][k] - x[i][0]);
    return min(l, r);
}

ll go(int i, int j) {
    if(i == n+1) return 0;
    ll & ans = dp[i][j];
    if(ans == -1) {
        ans = oo;
        fori(k,0,p) {
            ans = min(ans, go(i+1, k) + getMin(i, j, k));
        }
    }
    return ans;
}

void solve() {
    cin >> n >> p;
    fore(i,1,n) {
        fori(j,0,p) cin >> x[i][j];
        sort(x[i], x[i]+p);
    }
    memset(dp, -1, sizeof dp);
    cout << go(1, 0) << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}