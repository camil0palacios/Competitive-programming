#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 55;
int n, m; 
char a[MXN][MXN];
bool vis[MXN][MXN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool dfs(int x, int y) {
    vis[x][y] = 1;
    if(x == n - 1 && y == m - 1) return 1;
    for(int i = 0; i < 4; i++) {
        int mx = x + dx[i], my = y + dy[i]; 
        if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my] != '#' && !vis[mx][my] && dfs(mx, my)) 
            return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector< pair<int,int> > b, g;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];       
                if(a[i][j] == 'G') g.emplace_back(i, j);
                if(a[i][j] == 'B') b.emplace_back(i, j);
            }
        }
        for(int i = 0; i < b.size(); i++) {
            int x = b[i].first, y = b[i].second;
            if(x + 1 < n && a[x + 1][y] == '.') a[x + 1][y] = '#';
            if(x - 1 >= 0 && a[x - 1][y] == '.') a[x - 1][y] = '#';
            if(y + 1 < m && a[x][y + 1] == '.') a[x][y + 1] = '#';
            if(y - 1 >= 0 && a[x][y - 1] == '.') a[x][y - 1] = '#';
        }
        bool ok = 1;
        for(int i = 0; i < b.size(); i++) {
            int x = b[i].first, y = b[i].second;
            if(x + 1 < n && a[x + 1][y] == 'G') ok = 0;
            if(x - 1 >= 0 && a[x - 1][y] == 'G') ok = 0;
            if(y + 1 < m && a[x][y + 1] == 'G') ok = 0;
            if(y - 1 >= 0 && a[x][y - 1] == 'G') ok = 0;
        }
        for(int i = 0; i < g.size(); i++) {
            memset(vis, 0, sizeof vis);
            ok &=  dfs(g[i].first, g[i].second);
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}