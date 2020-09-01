#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 101;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m;
char a[MXN][MXN];
bool vis[MXN][MXN];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for(int i = 0; i < 8; i++) {
        int mx = x + dx[i], my = y + dy[i];
        if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my] != '*' && !vis[mx][my]) 
            dfs(mx, my);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> m && (n || m)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        memset(vis, 0, sizeof vis);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && a[i][j] != '*') {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}