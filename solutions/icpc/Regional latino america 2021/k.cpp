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

const int Mxk = 755;
const int Mxn = 1e4 + 5;
const int mod = 1e9 + 7;
int K, L, n;
int t[Mxk][Mxk];
ll p[Mxn];
ll dp[Mxn][Mxk];

void sum(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int lower(int i, int j) {
    int l = 1, r = K, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(t[j][mid]+L >= p[i]) ans = mid, r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int upper(int i, int j) {
    int l = 1, r = K, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(t[j][mid]-L <= p[i]) ans = mid, l = mid+1;
        else r = mid-1;
    }
    return ans;
} 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> K >> L;
    fore(i,1,K) fore(j,1,K) cin >> t[i][j];
    cin >> n;
    fore(i,1,n-1) cin >> p[i];
    fore(i,1,K) dp[n][i] = 1;
    forr(i,n-1,1) {
        fore(j,1,K) sum(dp[i+1][j], dp[i+1][j-1]);
        fore(j,1,K) {
            int l = lower(i, j);
            int r = upper(i, j);
            if(l != -1 && l <= r) {
                sum(dp[i][j], (dp[i+1][r] - dp[i+1][l-1] + mod) % mod); 
            }
        }
    }
    ll ans = 0;
    fore(i,1,K) ans = (ans + dp[1][i]) % mod;
    cout << ans << endl;
    return 0; 
}