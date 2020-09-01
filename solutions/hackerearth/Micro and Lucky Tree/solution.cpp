#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MAXN = 100100;
const int MOD = 1e9 + 7;
int N, M;
ll dp[MAXN][22];
int gc[22][22];
vector<int> g[MAXN];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void dfs(int u, int p) { 
    int child = 0;
    for(auto & v : g[u]) {
        if(v == p)continue;
        child++;
        dfs(v, u);
    }
    if(child) {
        for(int i = 0; i <= M; i++) {
            ll ans = 0;
            for(int j = 1; j <= M; j++) {
                int _g = gc[i][j];
                ll ways = 1;
                for(auto & v : g[u]) {
                    if(v == p) continue;
                    ways = (ways * dp[v][_g]) % MOD;
                }
                ans = (ans + ways) % MOD;
            }
            dp[u][i] = (dp[u][i] + ans) % MOD;
        }
    } else {
        for(int i = 0; i <= M; i++) {
            for(int j = 1; j <= M; j++) {
                dp[u][i] = (dp[u][i] + (gc[i][j] == 1)) % MOD;
            }
        }
    }
}

void computeGcd() {
    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= 20; j++) {
            gc[i][j] = gcd(i, j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    computeGcd();
    cin >> N >> M;
    for(int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    memset(dp, 0, sizeof dp);
    dfs(0, 0);
    ll ans = dp[0][0];
    cout << ans << endl;
    return 0;
}