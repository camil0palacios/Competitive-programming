#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 101;
const int MXS = 8;
int n, m, s;
int store[MXS];
int dp[MXN][MXN][1 << 8];
int dist[MXN][MXN];

int dfs(int u, int v, int msk) {
    if(msk == (1 << s) - 1) return 0;
    if(dp[u][v][msk] != -1) return dp[u][v][msk];
    int ans = INF;
    for(int i = 0; i < s; i++) {
        if(!((msk >> i) & 1)) {
            ans = min(ans, min(dfs(store[i], v, msk | (1 << i)) + dist[u][store[i]] , 
                    dfs(u, store[i], msk | (1 << i)) + dist[v][store[i]])
                );
            for(int j = 0; j < s; j++) {
                if(!((msk >> j) & 1) && i != j) {
                    ans = min(ans, dfs(store[i], store[j], msk | (1 << i) | (1 << j)) + dist[u][store[i]] + dist[v][store[j]]);
                }
            }
        }
    }
    return dp[u][v][msk] = ans;
}

void floyd() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void reset() {
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dist[i][j] = i == j ? 0 : INF;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    reset();
    for(int i = 0; i < m; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
    }
    cin >> s;
    for(int i = 0; i < s; i++) {
        cin >> store[i];
    }
    floyd();
    int u, v, msk = 0;
    cin >> u >> v;
    memset(dp, -1, sizeof dp);
    cout << dfs(u, v, 0) << endl;
    return 0;
}