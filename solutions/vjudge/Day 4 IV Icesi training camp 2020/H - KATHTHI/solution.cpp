#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
using namespace std;

const int INF = 1e9;
const int MXN = 1010;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char a[MXN][MXN];
int dist[MXN][MXN];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dist[i][j] = INF;
        }
    }
    deque<pair<int,int>> q;
    q.push_back(mp(0, 0));
    dist[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for(int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx < 0 && mx >= n && my < 0 && my >= m) continue;
            bool m = a[x][y] != a[mx][my];
            if(dist[x][y] + m < dist[mx][my]) {
                dist[mx][my] = dist[x][y] + m;
                if(m == 1) q.push_back(mp(mx, my));
                else q.push_front(mp(mx, my));
            }
        }
    }
    cout << dist[n - 1][m - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}