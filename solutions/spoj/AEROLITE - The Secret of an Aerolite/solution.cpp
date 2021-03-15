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

const int mod = 11380;
ll dp[11][11][11][31];

ll go(int a, int b, int c, int d) {
    if(d < 0) return 0;
    if(a + b + c == 0) return 1;
    ll & ans = dp[a][b][c][d];
    if(ans == -1) {
        ans = 0;
        fori(i,0,a) 
            fore(j,0,b) 
                fore(k,0,c) 
                    ans = (ans + go(i, j, k, d-1)*go(a-i-1, b-j, c-k, d)) % mod;
        fori(i,0,b) 
            fore(j,0,c) 
                ans = (ans + go(0, i, j, d-1)*go(a, b-i-1, c-j, d)) % mod;
        fori(i,0,c)
            ans = (ans + go(0, 0, i, d-1)*go(a, b, c-i-1, d)) % mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fori(i,0,10) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        memset(dp, -1, sizeof dp);
        ll ans = go(a, b, c, d) - go(a, b, c, d-1);
        if(ans < 0) ans += mod;
        cout << ans << endl;
    }
    return 0; 
}
