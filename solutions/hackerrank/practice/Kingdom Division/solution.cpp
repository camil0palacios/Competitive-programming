#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
const int MXN = 1e5 + 5;
int n;
vector<int> g[MXN];
ll dp[MXN][3][3];

bool leaf(int u, int par) {
    for(auto & v : g[u]) {
        if(v == par) continue;
        return 0;
    }
    return 1;
}

ll dfs(int u, int p, int color,int streak) {
    if(dp[u][color][streak] != -1) return dp[u][color][streak];
    if(leaf(u, p)) {
        if(streak == 1) return dp[u][color][streak]=0;
        if(streak == 2) return dp[u][color][streak]=1;
    }
    ll ans = 1, valid = 0, invalid = 1;
    for(auto & v : g[u]) {
        if(v == p) continue;
        valid = 0;
        valid += dfs(v, u, !color, 1);
        invalid = (invalid*dfs(v, u, !color, 1))%mod;
        valid += dfs(v, u, color, 2);
        ans=(ans * valid) % mod;
    }
    if(streak == 1) ans=(ans-invalid+mod)%mod;
    return dp[u][color][streak]=ans;
}

void reset() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][0][j] = dp[i][1][j] = -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        // u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    reset();
    ll ans = (dfs(1, 1, 0, 1) * 2) % mod;
    cout << ans << endl;
    return 0;
}