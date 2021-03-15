#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 105;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool a[MXN][MXN], sym[MXN][MXN];
int b[MXN][MXN];
int match[55];
bool vis[55];
vector<int> g[55];

bool bpm(int u) {
    for(auto & v: g[u]) {
        if(vis[v]) continue;
        vis[v] = 1;
        if(match[v] == -1 || bpm(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, k;
    while(cin >> n >> m, n || m) {
        cin >> k;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) a[i][j] = 1, b[i][j] = -1;
        for(int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            x--, y--;
            a[x][y] = 0;
        }
        int cnt = 0;
        bool cur = 0;
        for(int i = 0; i < n; i++) {
            if(m % 2 == 0)cur ^= 1;
            for(int j =0 ; j < m; j++) {
                if(a[i][j]) {
                    b[i][j] = cnt++;
                }
                sym[i][j] = cur;
                cur ^= 1;
            }
        }
        for(int i = 0; i < cnt; i++) {
            match[i] = -1;
            g[i].clear();
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] && sym[i][j]) {
                    for(int d = 0; d < 4; d++) {
                        int mx = i + dx[d], my = j + dy[d];
                        if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my]) {
                            g[b[i][j]].emplace_back(b[mx][my]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < cnt; i++) {
            for(int j = 0; j < cnt; j++) vis[j] = 0;
            if(bpm(i)) ans++;
        } 
        cout << ans << endl;
    }
    return 0; 
}