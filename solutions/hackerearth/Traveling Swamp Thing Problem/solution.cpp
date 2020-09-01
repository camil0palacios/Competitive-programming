#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Edge {
    int v, d, e;
    Edge(){}
    Edge(int v, int d, int e): v(v), d(d), e(e) {}
};

const int MXN = 15;
const int INF = 1e9;
int n, m, E;
int dp[MXN][1 << MXN][101];
vector<Edge> g[MXN];

int dfs(int u, int msk, int e) {
    if(msk == (1 << n) - 1) return 0;
    if(dp[u][msk][e] != -1) return dp[u][msk][e]; 
    int ans = INF;
    for(auto & edge : g[u]) {
        if(!((msk >> edge.v) & 1) && e + edge.e <= E) {
            ans = min(ans, dfs(edge.v, msk | (1 << edge.v), e + edge.e) + edge.d);
        } 
    }
    return dp[u][msk][e] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> E;
    for(int i = 0; i < m; i++) {
        int u, v, d, e; 
        cin >> u >> v >> d >> e;
        u--, v--;
        g[u].emplace_back(v, d, e);
        g[v].emplace_back(u, d, e);
    }
    memset(dp, -1, sizeof dp);
    int ans = dfs(0, 1, 0);
    cout << (ans < INF ? ans : -1) << endl;
    return 0;
}