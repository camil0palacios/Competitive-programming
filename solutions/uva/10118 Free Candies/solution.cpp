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
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 45;
int n;
int x[4][Mxn];
int dp[Mxn][Mxn][Mxn][Mxn];
vi s[4] = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}};

int check(int a,  int b, int c, int d, int na, int nb, int nc, int nd) {
    int cur = x[0][a-1]^x[1][b-1]^x[2][c-1]^x[3][d-1];
    int nxt = x[0][na-1]^x[1][nb-1]^x[2][nc-1]^x[3][nd-1]; 
    return nxt < cur;
}

int go(int a, int b, int c, int d) {
    if((a == n+1 && b == n+1 && c == n+1 && d == n+1) || 
        __builtin_popcount(x[0][a-1]^x[1][b-1]^x[2][c-1]^x[3][d-1]) == 5) return 0;
    int & ans = dp[a][b][c][d];
    if(ans == -1) {
        ans = 0;
        fori(i,0,4) {
            int na = a + s[i][0], nb = b + s[i][1], nc = c + s[i][2], nd = d + s[i][3];
            if(na <= n+1 && nb <= n+1 && nc <= n+1 && nd <= n+1) {
                int val = check(a, b, c, d, na, nb, nc, nd);
                ans = max(ans, go(na, nb, nc, nd) + val);
            }
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n, n) {
        memset(dp, -1, sizeof dp);
        memset(x, 0, sizeof x);
        fore(j,1,n) fori(i,0,4) cin >> x[i][j];
        fori(i,0,4) {
            fore(j,0,n) {
                x[i][j] = (1 << (x[i][j]-1));
                x[i][j] ^= x[i][j-1];
            }
        }
        cout << go(1,1,1,1) << endl;
    }
    return 0;
}