#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<long long, long long> pll;

const int MXN = 4e5 + 5;
int e[MXN], d[MXN], deg[MXN]; 
vector<int> g[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> e[i] >> d[i];
        for(int j = 0; j < d[i]; j++) {
            int v; cin >> v; v--;
            g[i].emplace_back(v);
            deg[v]++;
        }
    }
    priority_queue< pll, vector<pll>, greater<pll> > q;
    for(int i = 0; i < n; i++) {
        if(!deg[i]) {
            q.emplace(e[i], i);
        }
    }
    int ans = 0;
    for(int len = n - 1; len >= 0; len--) {
        int u = q.top().second;
        ans = max(ans, len + e[u]);
        q.pop();
        for(auto & v : g[u]) {
            deg[v]--;
            if(!deg[v]) q.emplace(e[v], v); 
        }

    }
    cout << ans << endl;
    return 0;
}