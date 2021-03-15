#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int n;
vector<int> g[MXN];
int dp0[MXN], dp1[MXN];

void dfs(int u, int p = -1) {
    for(auto & v: g[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp1[u] = max(dp1[u] + max(dp0[v], dp1[v]), dp0[u] + dp0[v] + 1);
        dp0[u] += max(dp0[v], dp1[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(0);
    cout << max(dp0[0], dp1[0]) << endl;
    return 0;
}