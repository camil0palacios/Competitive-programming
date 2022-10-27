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

const int mod = 1 << 15;
const int N = 2e5 + 5;
int dp[1 << 15][15];
int a[N];

int go(int x, int acc) {
    if(acc == 15 || x == 0) return x == 0 ? acc : 1e9;
    int & ans = dp[x][acc];
    if(ans != -1) return ans;
    ans = 1e9;
    ans = min(ans, go((x+1) % mod, acc+1));
    ans = min(ans, go((x*2) % mod, acc+1));
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    memset(dp, -1, sizeof dp);
    fori(i,0,n) {
        int ans = go(a[i], 0);
        cout << ans << ' ';
    }
    cout << endl;
    return 0; 
}