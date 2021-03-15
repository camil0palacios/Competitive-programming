#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
char a[1010][1010];
bool vis[1010][1010];


void dfs(int x, int y) {
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int mx = x + dx[i], my = y + dy[i];
        if(mx >= 0 && mx < n && my >= 0 && my < m && !vis[mx][my] && a[mx][my] != '#') 
            dfs(mx, my);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            cin >> a[i][j];
    int ans = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            if(a[i][j] == '.' && !vis[i][j]) {
                ans++;
                dfs(i, j);
            }
    cout << ans << endl;
    return 0;
}