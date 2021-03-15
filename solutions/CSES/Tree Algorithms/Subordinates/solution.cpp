#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int sz[MXN];
vector<int> g[MXN];

void dfs(int u, int p = 0) {
    sz[u] = 1;
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u = i + 1, v;
        cin >> v; v--;
        g[v].emplace_back(u);
    }
    dfs(0);
    for(int i = 0; i < n; i++) {
        cout << sz[i] - 1 << ' ';
    }
    return 0;
}