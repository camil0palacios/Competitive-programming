#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
using namespace std;

typedef pair<int,int> ii;
const int INF = 1e9;
const int MAXN = 101;
int dx[8] = { 1, 2,  1,  2, -1, -2, -1, -2 };
int dy[8] = { 2, 1, -2, -1,  2,  1, -2, -1 };

int n, m, k;
char a[MAXN][MAXN];

int cost[16][16];
int px[16], py[16];

void dijkstra(int x, int y, int idx){
    int dist[MAXN][MAXN];    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dist[i][j] = INF;
    dist[x][y] = 0;
    set< pair<int,ii> > q;
    q.insert(mp(dist[x][y], mp(x, y)));
    while(!q.empty()){
        x = q.begin() -> second.first;
        y = q.begin() -> second.second;
        int dis = q.begin() -> first;
        q.erase(q.begin());
        if(dis > dist[x][y])continue;
        for(int i = 0; i < 8; i++){
            int mx = x + dx[i], my = y + dy[i];
            if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my] != '#' && dist[x][y] + 1 < dist[mx][my]){
                q.erase(mp(dist[mx][my], mp(mx, my)));
                dist[mx][my] = dist[x][y] + 1;
                q.insert(mp(dist[mx][my], mp(mx, my)));
            }
        }
    }
    for(int i = 0; i < k; i++){
        cost[idx][i] = dist[px[i]][py[i]];
    }
}

int dp[16][(1 << 16)];

int go(int lst, int msk){
    if(msk == (1 << k) - 1)return cost[lst][0];
    if(dp[lst][msk] != -1)return dp[lst][msk];
    int ans = INF;
    for(int i = 0; i < k; i++){
        if(!((msk >> i) & 1)){
            ans = min(ans, go(i, msk | (1 << i)) + cost[lst][i]);
        }
    }
    return dp[lst][msk] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> m >> k, n || m || k){
        k++;
        int cnt = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                if(a[i][j] == 'P'){
                    px[cnt] = i, py[cnt++] = j;
                }
                if(a[i][j] == 'C'){
                    px[0] = i, py[0] = j;
                }
            }
        }
        for(int i = 0; i < k; i++){
            dijkstra(px[i], py[i], i);
        }
        memset(dp, -1, sizeof dp);
        cout << go(0,0) << endl;
    }
    return 0;
}