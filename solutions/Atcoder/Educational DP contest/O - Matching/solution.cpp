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

const int mod = 1e9 + 7;
const int Mxn = 22;
int n;
bool a[Mxn][Mxn];
ll dp[1 << Mxn];

ll go(int msk) {
    if(msk == (1 << n)-1) return 1;
    if(dp[msk] != -1) return dp[msk];
    ll ans = 0;
    int i = __builtin_popcount(msk);
    fori(j,0,n) {
        if(!((msk >> j) & 1) && a[i][j]) {
            ans = (ans + go(msk | (1 << j))) % mod;
        } 
    }
    return dp[msk] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fori(i,0,n) fori(j,0,n) cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    cout << go(0) << endl;
    return 0; 
}