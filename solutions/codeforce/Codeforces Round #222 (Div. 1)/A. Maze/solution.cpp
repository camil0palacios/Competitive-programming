#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 505;
int n, m, k;
int vis[Mxn][Mxn];
int ok[Mxn][Mxn];
int dx[4] = {1,0,-1, 0};
int dy[4] = {0,1, 0,-1};
string a[Mxn];

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs2(int x, int y, int & t) {
    vis[x][y] = 1; t--;
    if(!t) return 1;
    fori(i,0,4) {
        int mx = x + dx[i], my = y + dy[i];
        if(check(mx, my) && !vis[mx][my] && a[mx][my] == '.' && dfs2(mx, my, t)) return 1;
    } 
    return 0;
}

int dfs(int x, int y) {
    vis[x][y] = 1;
    int cnt = 1;
    fori(i,0,4) {
        int mx = x + dx[i], my = y + dy[i];
        if(check(mx, my) && !vis[mx][my] && a[mx][my] == '.')
            cnt += dfs(mx, my);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    fori(i,0,n) {
        cin >> a[i];
    }
    fori(i,0,n) {
        bool ok = 0;
        fori(j,0,m) {
            if(a[i][j] == '.') { 
                int t = dfs(i, j) - k;
                memset(vis, 0, sizeof vis);
                dfs2(i, j, t);
                ok = 1;
                break; 
            }
        }
        if(ok) break;
    }    
    fori(i,0,n) 
        fori(j,0,m)
            if(a[i][j] == '.' && !vis[i][j]) a[i][j] = 'X';
    fori(i,0,n) cout << a[i] << endl;
    return 0; 
}