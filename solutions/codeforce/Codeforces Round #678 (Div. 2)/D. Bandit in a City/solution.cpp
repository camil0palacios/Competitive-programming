#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
ll a[MXN], sz[MXN];
vector<int> g[MXN];

void dfs(int u) {
    if(g[u].size() == 0) sz[u] = 1;
    for(auto & v : g[u]) {
        dfs(v);
        sz[u] += sz[v];
        a[u] += a[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int p; 
        cin >> p; 
        p--;
        g[p].emplace_back(i);
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    dfs(0);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, (ll)ceil(a[i]*1.0/sz[i]));
    }
    cout << ans << endl;
    return 0;
}