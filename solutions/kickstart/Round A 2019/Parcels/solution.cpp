#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 250;
const int INF = 1e9;
char a[MAXN][MAXN];
bool s[MAXN][MAXN];
int dis[MAXN][MAXN];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int n, int m) {
    memset(dis, -1, sizeof dis);
    queue<pii> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j]) {
                dis[i][j] = 0;
                q.push(mp(i, j));
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx >= 0 && mx < n && my >= 0 && my < m && dis[mx][my] == -1) {
                dis[mx][my] = dis[x][y] + 1;
                q.push(mp(mx, my));
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dis[i][j] == -1)dis[i][j] = INF;
        }
    }
}

bool can(int n, int m, int x) {
    int maxx = INF, minx = -INF, maxy = INF, miny = -INF;
    bool ok = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dis[i][j] <= x)continue;
            maxx = min(maxx, i + j + x);
            minx = max(minx, i + j - x);
            maxy = min(maxy, i - j + x);
            miny = max(miny, i - j - x);
            ok = 0;
        }
    }
    if(ok)return 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int a = i + j, b = i - j; 
            if(minx <= a && a <= maxx && miny <= b && b <= maxy) {
                return 1;
            }
        }
    }
    return 0;
}

void sol() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            s[i][j] = (a[i][j] == '1' ? 1 : 0);
        }
    }
    bfs(n, m);
    int l = 0, r = INF;
    while(l < r){
        int mid = (l + r) >> 1;
        if(can(n, m, mid))r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}