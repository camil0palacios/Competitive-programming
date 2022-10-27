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

string s;
int k;
int dp[20][2][2][1 << 11];
string res;

int go(int idx, int bot, bool z, int msk) {
    if(__builtin_popcount(msk) > k) return 0;
    if(idx == sz(s)) return 1;
    int & ans = dp[idx][bot][z][msk]; 
    if(ans != -1) return ans;
    int mn = bot ? s[idx]-'0' : 0;
    ans = 0;
    fore(i,mn,9) {
        if(go(idx+1, bot && i == mn, z || i != 0, z || i != 0 ? msk | (1 << i) : msk)) {
            res += char(i + '0');
            return ans = 1;
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> s >> k;
        reverse(all(s));    
        int d = 16 - sz(s);
        fori(i,0,d) s += '0';
        reverse(all(s));
        memset(dp, -1, sizeof dp);
        res.clear();
        go(0, 1, 0, 0);
        int i = sz(res)-1;
        while(res[i] == '0') i--;
        res = res.substr(0, i+1);
        reverse(all(res));
        cout << res << endl;
    }
    return 0; 
}