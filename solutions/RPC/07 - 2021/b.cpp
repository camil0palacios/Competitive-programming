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

int dx[8] = {1, 0, -1,  0, 1,  1, -1, -1};
int dy[8] = {0, 1,  0, -1, 1, -1,  1, -1};

const int Mxn = 15;
const int Mxs = 110;
int n, m;
char a[Mxn][Mxn];
string s;
int dp[Mxn][Mxn][Mxs][9][2*Mxs];

int go(int x, int y, int idx, int d, int k) {
    if(k < 0) return 0;
    if(idx == sz(s)) return k == 0;
    int & ans = dp[x][y][idx][d][k];
    if(ans == -1) {
        ans = 0;
        fori(i,0,8) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx >= 0 && mx < n && my >= 0 && my < m && s[idx] == a[mx][my]) {
                ans |= go(mx, my, idx+1, i, k - (d != 8 ? (i != d) : 0));
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin >> n >> m;
    fori(i,0,n) fori(j,0,m) cin >> a[i][j];
    cin >> k >> s;
    memset(dp, -1, sizeof dp);
    bool ans = 0;
    fori(i,0,n) {
        fori(j,0,m) {
            if(s[0] == a[i][j]) {
                ans |= go(i, j, 1, 8, k);
                if(ans) goto res;
            }
        }
    }
    res:
    cout << (ans ? "Yes" : "No") << endl;
    return 0; 
}