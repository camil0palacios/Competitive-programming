#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int n;
vector<int> g[MXN];
int depth[MXN];
int dp1[MXN], dp2[MXN];
int ans;

int dfs(int u, int p = -1) {
    int mx1 = 0, mx2 = 0;
    for(auto & v: g[u]) {
        if(v == p) continue;
        int tmp = dfs(v, u);
        if(mx1 < tmp) {
            int auxx = mx1;
            mx1 = tmp;
            mx2 = auxx;
        }
        else if(mx2 < tmp) {
            mx2 = tmp;
        }
    }
    ans = max(ans, mx1 + mx2); 
    return mx1 + 1;
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
    ans = 0;
    dfs(0);
    cout << ans << endl;
    return 0;
}