#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<char> vc;
const int INF = 1e9;
char a[1010][1010];
char dir[4] = {'D', 'R', 'U', 'L'};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int si, sj, ti, tj;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') si = i, sj = j;
            if(a[i][j] == 'B') ti = i, tj = j;
        }
    }
    vector<vi> dist(n, vi(m, INF));
    vector<vii> parent(n, vii(m, {-1,-1}));
    vector<vc> path(n, vc(m, '?')); 
    queue<pair<int,int>> q;
    q.push({si, sj});
    dist[si][sj] = 0;
    bool ok = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == ti && y == tj) {
            ok = 1;
            break;
        }
        for(int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my] != '#' && dist[x][y] + 1 < dist[mx][my]) {
               path[mx][my] = dir[i];
               dist[mx][my] = dist[x][y] + 1;
               parent[mx][my] = {x, y}; 
               q.push({mx, my});
            }
        }
    }
    if(ok) {
        cout << "YES" << endl;
        cout << dist[ti][tj] << endl; 
        string ans;
        int x = ti, y = tj;
        while(x != si || y != sj) {
            ans += path[x][y];
            int tmpx = parent[x][y].first;
            int tmpy = parent[x][y].second;
            x = tmpx, y = tmpy;
        }
        reverse(all(ans));
        cout << ans << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}