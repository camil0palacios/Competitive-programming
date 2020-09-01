#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

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
    vector<int> lvl(n + 1, -1);
    queue<int> q;
    lvl[0] = 0;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto & v: g[u]) {
            if(lvl[v] == -1) {
                lvl[v] = lvl[u] + 1;
                q.push(v);
            } 
        }
    }
    cout << lvl[n - 1] - 1 << endl;
    return 0;
}