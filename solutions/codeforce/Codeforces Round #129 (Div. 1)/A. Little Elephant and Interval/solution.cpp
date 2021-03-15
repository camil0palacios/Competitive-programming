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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

ll dp[19][2][2][11][11];
string s;

ll go(int idx, bool top, bool z, int x, int y) {
    if(idx == sz(s)) return x == y;
    ll & ans = dp[idx][top][z][x][y];
    if(ans == -1) {
        ans = 0;
        int mx = top ? s[idx]-'0' : 9;
        fore(i,0,mx) {
            ans += go(idx+1, top && i == mx, z || i > 0, x ? x : i > 0 ? i : 0, i);
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll l, r;
    cin >> l >> r;
    s = to_string(l-1);
    memset(dp, -1, sizeof dp);
    ll ans = go(0,1,0,0,0);
    s = to_string(r);
    memset(dp, -1, sizeof dp);
    cout << go(0,1,0,0,0) - ans << endl;
    return 0; 
}