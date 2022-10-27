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
const int Mxn = 110;
const int Mxm = 15;
int n, m;
char a[Mxn][Mxm];
int dp[Mxn][Mxm][1 << Mxm];

int get_bit(int x, int i) {
    return (x >> i) & 1;
}

int down_bit(int x, int i) {
    return x & ~(1 << i);
}

int check(int i, int fl) {
    int tot = 0, cnt = 0;
    fori(j,0,m) {
        int x = a[i][j] == '#';
        int y = a[i-1][j] == '#';
        tot += x + y;
        if((fl >> j) & 1) cnt += x + y; 
    }
    return tot == cnt;
}

int go(int i, int j, int fl) {
    if(i < 0) return 0;
    auto & ans = dp[i][j][fl];
    if(ans == -1) {
        ans = oo;
        if(j >= m && check(i, fl)) ans = min(ans, go(i-2, 0, fl));
        else {
            if(j+1 < m && (get_bit(fl, j) || get_bit(fl, j+1) || i == n-1))
                ans = min(ans, go(i, j+2, fl|(1 << j)|(1 << (j+1))) + 1);
            if(j+1 <= m) ans = min(ans, go(i, j+1, down_bit(fl, j)));
        }
    }
    return ans;
} 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fori(i,0,n) fori(j,0,m) cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    cout << go(n-1, 0, 0) << endl;
    return 0; 
}