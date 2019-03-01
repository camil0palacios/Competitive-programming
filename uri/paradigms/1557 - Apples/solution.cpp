#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[25][25][2005], TMAX, N, M;
int dx[9] = {1,0,-1, 0,1,-1,-1, 1,0};
int dy[9] = {0,1, 0,-1,1, 1,-1,-1,0};
bool v[25][25][2005];

int go(int x, int y, int t){
    if(x > N || y > M || x < 1 || y < 1 || t > TMAX)return 0;
    if(dp[x][y][t] != -1)return dp[x][y][t];
    int ans = 0;
    for(int i = 0; i < 9; i++){
        int nx = x + dx[i], ny = y + dy[i];
        ans = max(ans, go(nx,ny,t+1));   
    }
    return dp[x][y][t] = ans + v[x][y][t];
}

int main(){
    
    int n, m, k, x, y, t;
    while(cin >> n >> m >> k, n, m, k){
        memset(v, 0, sizeof v);
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < k; i++){
            cin >> x >> y >> t;
            v[x][y][t] = 1;
        }
        TMAX = t, N = n, M = m;
        cin >> x >> y;
        cout << go(x,y,0) << endl;
    }
    return 0;
}