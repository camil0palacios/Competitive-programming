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

// dont forget graph g and transpose t
const int Mxn = 2020;
map<char, ii> to({{'L', mp(-1, 0)}, {'R', mp(1, 0)}, {'U', mp(0, -1)}, {'D', mp(0, 1)}}); 
bool vis[Mxn][Mxn], sz[Mxn][Mxn];

void dfs1(int x, int y) {
    vis[x][y] = 1;
    int mx = x + to[g[x][y]].sd, my = y + to[g[x][y]].ft;
    if(mx >= 0 && mx < n && my >= 0 && my < m && !vis[mx][my]) dfs1(mx, my);
    st.push({x, y});
}

void dfs2(int x, int y, int c) {
    vis[x][y] = 1, cmp[x][y] = c, szcmp[c]++;
    int mx = x + to[g[x][y]].sd, my = y + to[g[x][y]].ft;
    if(mx >= 0 && mx < n && my >= 0 && my < m && !vis[mx][my]) dfs2(mx, my, c);
}

void kosarajus(int n, int m) {
    memset(vis, 0, sizeof vis);
    fori(i,0,n) fori(j,0,m) if(!vis[i][j]) dfs1(i, j);
    memset(vis, 0, sizeof vis);
    int c = 0;
    while(!st.empty()) {
        int x = st.top().ft;
        int y = st.top().sd;
        st.pop();
        if(!vis[x][y]) dfs2(x, y, c++);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        fori(i,0,n) fori(j,0,m) cin >> a[i][j];
    }
    return 0; 
}