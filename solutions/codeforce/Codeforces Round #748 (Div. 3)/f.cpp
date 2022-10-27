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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int oo = 1e9;
const int Mxn = 45;
const int z = 45;
int n, A, B;
string s, res;
int dp[Mxn][Mxn][Mxn][4][2*Mxn];

int go(int i, int ra, int rb, int msk, int d) {
    if(i == n) return !ra && !rb && msk == 3 ? abs(d) : oo;
    int & ans = dp[i][ra][rb][msk][z+d];
    if(ans == -1) {
        int x = s[i]-'0';
        ans = min(go(i+1, (ra*10 + x) % A, rb, msk | 1, d + 1), 
                go(i+1, ra, (rb*10 + x) % B, msk | 2, d - 1));
    }
    return ans;
}

void rec(int i, int ra, int rb, int msk, int d)  {
    if(i == n) return;
    int cur =  dp[i][ra][rb][msk][z+d];
    int x = s[i]-'0';
    if(cur == go(i+1, (ra*10 + x) % A, rb, msk | 1, d + 1)) {
        res += 'R';
        rec(i+1, (ra*10 + x) % A, rb, msk | 1, d + 1);
    } else {
        res += 'B';
        rec(i+1, ra, (rb*10 + x) % B, msk | 2, d - 1);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> A >> B >> s;
        memset(dp, -1, sizeof dp);
        if(go(0, 0, 0, 0, 0) != oo) {
            res = "";
            rec(0, 0, 0, 0, 0);
            cout << res << endl;
        } else cout << -1 << endl;
    }
    return 0; 
}