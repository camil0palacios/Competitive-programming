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

const int Mxn = 1100;
int n, m;
char a[Mxn][Mxn];
int dx[4] = {1, 0,-1, 0};
int dy[4] = {0, 1, 0,-1};
char t[4] = {'D','I','M','A'};
int dp[Mxn][Mxn][4];
bool cycle;
int col[Mxn][Mxn];

int go(int i, int j, int p) {
    if(dp[i][j][p] != -1) return dp[i][j][p];
    int ans = 0;
    fori(d,0,4) {
        int mx = i + dx[d], my = j + dy[d];
        if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my] == t[p]) {
            ans = max(ans, go(mx, my, (p + 1) % 4) + (t[p] == 'A'));
        }
    }
    return dp[i][j][p] = ans;
}

int dfs(int i, int j, int p) {
    col[i][j] = 1;
    fori(d,0,4) {
        int mx = i + dx[d], my = j + dy[d];
        if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my] == t[p]) { 
            if(!col[mx][my] && dfs(mx, my, (p + 1) % 4)) return 1;
            else if(col[mx][my] == 1) return 1;
        }
    }
    col[i][j] = 2;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fori(i,0,n) fori(j,0,m) cin >> a[i][j];
    fori(i,0,n) fori(j,0,m) {
        if(a[i][j] == 'D' && dfs(i,j,1)) {
            cout << "Poor Inna!" << endl;
            return 0;
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    fori(i,0,n) fori(j,0,m) {
        if(a[i][j] == 'D') ans = max(ans, go(i,j,1));
    }
    if(ans) cout << ans << endl;
    else cout << "Poor Dima!" << endl;
    return 0;
}