#include <bits/stdc++.h>
using namespace std;

const int NM = 1e3 + 5;
char g[NM][NM];
bool done[NM][NM];

int h, n, m;

int dx_p[6] = {-1,-1, 0,0,1,1};
int dy_p[6] = { 0, 1,-1,1,0,1};

int dx[6] = {-1,-1, 0,0, 1,1};
int dy[6] = {-1, 0,-1,1,-1,0};

void dfs(int x, int y, int & cnt){
    done[x][y] = 1;
    cnt++;
    for(int i = 0; i < 6; i++){
        int mx, my;
        if(x % 2){
            mx = x + dx_p[i], my = y + dy_p[i];
        }else{
            mx = x + dx[i], my = y + dy[i];
        }
        if(mx >= 0 && mx < n && my >= 0 && my < m && !done[mx][my] && g[mx][my] == '.')
            dfs(mx,my,cnt);
    }
}

int main(){
    cin >> h >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    vector<int> v;
    memset(done, 0, sizeof done);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!done[i][j] && g[i][j] == '.'){
                int cnt = 0;
                dfs(i,j,cnt);
                v.emplace_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for(auto & i : v){
        if(h <= 0)break;
        h -= i;
        ans++;
    }
    cout << ans << endl;
    return 0;
}