#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 25;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char a[MXN][MXN];
bool vis[MXN*MXN];
int mark[MXN][MXN], match[MXN*MXN];
vector<int> g[MXN*MXN];

bool bpm(int u) {
    for(auto & v: g[u]) {
        if(vis[v]) continue;
        vis[v] = 1;
        if(match[v] == 0 || bpm(match[v])) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int solve() {
    int n, m;
    cin >> n >> m;
    memset(mark, 0, sizeof mark);
    int nodes = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '*') mark[i][j] = ++nodes;
        }
    }
    for(int i = 1; i <= nodes; i++) g[i].clear();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mark[i][j]) {
                for(int k = 0; k < 4; k++) {
                    int mx = i + dx[k], my = j + dy[k];
                    if(mx >= 0 && mx < n && my >= 0 && my < m && mark[mx][my]) {
                        g[mark[i][j]].emplace_back(mark[mx][my]);
                    }
                }
            }
        }
    }
    int ans = 0;
    memset(match, 0, sizeof match);
    for(int i = 1; i <= nodes; i++) {
        memset(vis, 0, sizeof vis);
        if(bpm(i)) ans++;
    }
    ans /= 2;
    return nodes - ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": " << solve() << endl;
    }
    return 0;
}