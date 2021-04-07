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

const int Mxn = 505;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;
int a[Mxn][Mxn];
bool vis[Mxn][Mxn];

void dfs(int x, int y) {
    vis[x][y] = 1;
    fori(i,0,4) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if(mx >= 0 && mx < n && my >= 0 && my < m && !vis[mx][my] && 
            a[x][y] >= a[mx][my] && a[mx][my])
            dfs(mx, my);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    vector<pair<int,ii>> p;
    fori(i,0,n) fori(j,0,m) {
        cin >> a[i][j];
        p.eb(a[i][j], mp(i, j));
    }
    sort(all(p), greater<pair<int,ii>>());
    int ans = 0;
    for(auto & pt : p) {
        int x = pt.sd.ft, y = pt.sd.sd;
        if(!vis[x][y] && a[x][y]) {
            dfs(x, y);
            if(a[x][y] > 1) ans++;
        }
    }
    cout << ans << endl;
    return 0; 
}