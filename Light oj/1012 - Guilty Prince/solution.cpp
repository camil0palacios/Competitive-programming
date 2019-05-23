#include <bits/stdc++.h>
using namespace std;

const int NM = 25; 
int n, m;
int dx[4] = {1,0,-1, 0};
int dy[4] = {0,1, 0,-1}; 
bool vis[25][25];
char g[NM][NM];

void dfs(int x, int y, int & cnt){
    vis[x][y] = 1;
    cnt++;
    for(int i = 0; i < 4; i++){
        int mx = x + dx[i], my = y + dy[i];
        if(mx >= 0 && mx < m && my >= 0 && my < n && !vis[mx][my] && g[mx][my] != '#'){
            dfs(mx,my,cnt);
        }
    }
}

void solve(){
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
            if(g[i][j] == '@')x = i, y = j;
        }
    }
    memset(vis,0,sizeof vis);
    int ans = 0;
    dfs(x,y,ans);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve(); 
    }
    return 0;
}