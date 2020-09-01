#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;

const int INF = 1e9;
const int MXN = 205;
int n, m;
vi g[MXN];
int cost[MXN][MXN], vis[MXN];
int dp[1 << 22];

int Dp(int msk, vi & v) {
    if(msk == (1 << (int)v.size()) - 1) return 0;
    if(dp[msk] != -1) return dp[msk];
    int ans = INF; 
    for(int i = 0; i < v.size(); i++) {
        if(!((msk >> i) & 1)) {
            for(int j = i + 1; j < v.size(); j++) {
                if(!((msk >> j) & 1)) { 
                    ans = min(ans, Dp(msk | (1 << i) | (1 << j), v) + cost[v[i]][v[j]]);
                }
            }
            break;
        }
    }
    return dp[msk] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) g[i].emplace_back(i);
    for(int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        cost[u][v] = cost[v][u] = c;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(g[i].size() & 1) {
            cout << "impossible" << endl;
            return 0;
        }
        if(vis[i]) continue;
        for(auto v : g[i]) vis[v] = 1;
        memset(dp, -1, sizeof dp);
        ans += Dp(0, g[i]);
    }
    cout << ans << endl;
    return 0;
}