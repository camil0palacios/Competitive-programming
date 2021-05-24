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

const int mod = 998244353;
const int Mxn = 1e5 + 5;
string s;
ll dp[Mxn][2][10][2];

ll go(int idx, bool top, int lst, int z) {
    if(idx == sz(s)) return 1;
    ll & ans = dp[idx][top][lst][z];
    if(ans == -1) {
        ans = 0;
        int mx = top ? s[idx]-'0' : 9;
        fore(i,0,mx) {
            if(!z || i != lst)
                ans = (ans + go(idx + 1, top && i == mx, i, z || i > 0)) % mod;
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    int acc = 0;
    forr(i,sz(s)-1,0) {
        if(s[i] == '0') s[i] = '9', acc = 1;
        else {
            if(i == 0 && s[i] == '1');
            else acc = 0;
            s[i]--;
            break;
        }
    }
    if(acc) s = s.substr(1);
    memset(dp, -1, sizeof dp);
    ll ans = go(0, 1, 0, 0);
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << (go(0, 1, 0, 0) - ans + mod) % mod << endl;
    return 0; 
}