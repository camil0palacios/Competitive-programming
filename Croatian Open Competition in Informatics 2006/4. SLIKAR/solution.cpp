#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dx[4] = {1,0,-1, 0};
int dy[4] = {0,1, 0,-1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    char g[n][m];
    queue<pair<int,int>> q;
    int lava[n][m], mov[n][m];
    memset(lava, -1, sizeof lava);
    memset(mov, -1, sizeof mov);
    int si = -1, sj = -1, di = -1, dj = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'S'){
                si = i, sj = j;
                g[i][j] = '.';
            }
            if(g[i][j] == 'D'){
                di = i, dj = j;
            }
            if(g[i][j] == '*'){
                lava[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int mx = x + dx[i], my = y + dy[i];
            if(mx >= 0 && mx < n && my >= 0 && my < m && lava[mx][my] == -1 && g[mx][my] == '.'){
                lava[mx][my] = lava[x][y] + 1;
                q.push({mx,my});
            }
        }
    }
    q.push({si,sj});
    mov[si][sj] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int mx = x + dx[i], my = y + dy[i];
            if(mx >= 0 && mx < n && my >= 0 && my < m && mov[mx][my] == -1 && g[mx][my] != 'X' && (lava[mx][my] > mov[x][y] + 1 || lava[mx][my] == -1)){
                mov[mx][my] = mov[x][y] + 1;
                q.push({mx,my});
            }
        }
    }

    if(mov[di][dj] != -1){
        cout << mov[di][dj] << endl;
    }else{
        cout << "KAKTUS" << endl;
    }
    return 0;
}