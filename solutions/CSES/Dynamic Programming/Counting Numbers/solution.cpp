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
typedef vector<ll> vll;

const int Mxn = 19;
string s;
ll dp[Mxn][2][2][11];

ll go(int idx, bool top, bool z, int lst) {
    if(idx == sz(s)) return 1;
    ll & ans = dp[idx][top][z][lst];
    if(ans != -1) return ans;
    ans = 0;
    int mx = top ? s[idx]-'0' : 9;
    for(int i = 0; i <= mx; i++) {
        if(z && i == lst) continue;
        ans += go(idx + 1, top && i == mx, z || i > 0, i);    
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    s = to_string(a-1);
    memset(dp, -1, sizeof dp);
    ll ans = go(0,1,0,10);
    s = to_string(b);
    memset(dp, -1, sizeof dp);
    cout << go(0,1,0,10) - ans << endl;
    return 0; 
}