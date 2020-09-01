#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 30;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
bool vis[MXN][MXN];
char a[MXN][MXN];

int dfs(int x, int y) {
    vis[x][y] = 1;
    int ans = 1;
    for(int i = 0; i < 4; i++){
        int mx = x + dx[i], my = y + dy[i];
        if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my] == '.' && !vis[mx][my]) {
            ans += dfs(mx, my);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cin >> m >> n;
        int sx = 0, sy = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                if(a[i][j] == '@') sx = i, sy = j;
            }
        }
        // cout << sx << ' ' << sy << endl; 
        memset(vis, 0, sizeof vis);
        cout << "Case " << cs << ": " << dfs(sx, sy) << endl;
    }
    return 0;
}