#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 1e5 + 5;
vector<int> g[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> dist(n, INF);
    vector<int> p(n, -1);
    queue<int> q;
    dist[0] = 0;
    p[0] = -1;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == n - 1) break;
        for(auto & v : g[u]) {
            if(dist[v] > dist[u] + 1) {
                p[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    if(dist[n - 1] < INF) {
        vector<int> path;
        for(int i = n - 1; i != -1; i = p[i]) {
            path.emplace_back(i);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for(int & i : path) {
            cout << i + 1 << ' ';
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}