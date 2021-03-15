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

const int oo = 1e9;
const int Mxn = 515;
int n;
char a[Mxn][Mxn];
int col[Mxn][Mxn][2];
int dp[Mxn][Mxn][Mxn];

int sum(int x, int y, int l, bool c) {
    int xp = x-l, yp = y-l;
    return col[x][y][c] - col[xp][y][c] - col[x][yp][c] + col[xp][yp][c];
}

int calc(int msk, int l, vii & x) {
    vii v;
    fori(i,0,4) if((msk >> i)&1) v.eb(x[i]);
    int ans = oo;
    fori(i,0,2) ans = min(ans, l*l - sum(v[0].ft, v[0].sd, l, i) + l*l - sum(v[1].ft, v[1].sd, l, i^1));
    return ans;
}

int go(int x, int y, int l) {
    if(l == 1) return 0;
    if(dp[x][y][l] != -1) return dp[x][y][l];
    int ans = oo;
    int xp = x-l/2, yp = y-l/2;
    vii v({ {x, y}, {x, yp}, {xp, y}, {xp, yp} });
    int msk = (1 << 4) - 1;
    fori(i,0,4) {
        msk ^= 1 << i;
        fori(j,i+1,4) {
            msk ^= 1 << j;
            ans = min(ans, go(v[i].ft, v[i].sd, l/2) + go(v[j].ft, v[j].sd, l/2) + calc(msk, l/2, v));
            msk ^= 1 << j;
        }
        msk ^= 1 << i;
    }
    return dp[x][y][l] = ans;
}

void fill_mat(int x, int y, int l, bool c) {
    int xp = x-l+1, yp = y-l+1;
    fore(i,xp,x) fore(j,yp,y) a[i][j] = char(c + '0');
}

void fill(int msk, int l, vii & x) {
    vii v;
    fori(i,0,4) if((msk >> i)&1) v.eb(x[i]);
    int mx = oo, j = 0;
    fori(i,0,2) {
        int r = l*l - sum(v[0].ft, v[0].sd, l, i) + l*l - sum(v[1].ft, v[1].sd, l, i^1);
        if(r < mx) j = i, mx = r;
    }
    fill_mat(v[0].ft, v[0].sd, l, j);
    fill_mat(v[1].ft, v[1].sd, l, j^1);
}

void rec(int x, int y, int l) {
    if(l == 1) return;
    int cur = go(x, y, l);
    int xp = x-l/2, yp = y-l/2;
    vii v({ {x, y}, {x, yp}, {xp, y}, {xp, yp} });
    int msk = (1 << 4) - 1;
    fori(i,0,4) {
        msk ^= 1 << i;
        fori(j,i+1,4) {
            msk ^= 1 << j;
            if(cur == go(v[i].ft, v[i].sd, l/2) + go(v[j].ft, v[j].sd, l/2) + calc(msk, l/2, v)) {
                fill(msk, l/2, v);
                rec(v[i].ft, v[i].sd, l/2);
                rec(v[j].ft, v[j].sd, l/2);
                return;
            }
            msk ^= 1 << j;
        }
        msk ^= 1 << i;
    }
}

void solve() {
    cin >> n;
    fore(i,1,n) fore(j,1,n) cin >> a[i][j];
    fore(i,1,n) fore(j,1,n) { 
        col[i][j][0] = col[i-1][j][0] + col[i][j-1][0] - col[i-1][j-1][0] + (a[i][j] == '0');
        col[i][j][1] = col[i-1][j][1] + col[i][j-1][1] - col[i-1][j-1][1] + (a[i][j] == '1');        
    }
    memset(dp, -1, sizeof dp);
    rec(n,n,n);
    cout << go(n,n,n) << endl;
    fore(i,1,n) {
        fore(j,1,n) cout << a[i][j];
        cout << endl;
    } 
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}