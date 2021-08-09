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
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dp[Mxn][Mxn][3][5];

bool dfs(int x, int y, int t, int d = 4) {
    if(a[x][y] == 'T') return 1;
    int & ans = dp[x][y][t][d]; 
    if(ans != -1) return ans;
    ans = 0;
    fori(i,0,4) {
        int mx = x + dx[i];
        int my = y + dy[i];
        int nt = d == 4 ? t : t + (d != i);
        if(mx >= 0 && mx < n && my >= 0 && my < m && nt < 3 && a[mx][my] != '*' && dfs(mx, my, nt, i)) 
            return ans = 1;
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    int x, y;
    fori(i,0,n) fori(j,0,m) {
        cin >> a[i][j];
        if(a[i][j] == 'S') x = i, y = j;
    }
    memset(dp, -1, sizeof dp);
    cout << (dfs(x, y, 0) ? "YES" : "NO") << endl;
    return 0; 
}