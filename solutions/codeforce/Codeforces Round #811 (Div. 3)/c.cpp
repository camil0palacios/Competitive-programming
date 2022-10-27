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

int s;
string res;
const int N = 10;
int dp[N][2][1 << 11];

int check(int msk) {
    int ans = 0;
    fore(i,0,9) if((msk >> i) & 1) ans += i;
    return ans;
}

int rec(int i, int z, int msk) {
    int p = check(msk);
    if(i == N) return p == s;
    int & ans = dp[i][z][msk];
    if(ans == -1) {
        ans = 0;
        fore(j,0,9) {
            int nz = z || j != 0;
            if(!((msk >> j) & 1) 
                && p+j <= s 
                && rec(i+1, nz, nz ? msk | (1 << j) : 0)) {
                res += char(j + '0');
                return ans = 1;
            }
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        res.clear();
        memset(dp, -1, sizeof dp);
        rec(0, 0, 0);
        reverse(all(res));
        int i = 0;
        while(res[i] == '0') i++;
        cout << res.substr(i) << endl;
    }
    return 0; 
}