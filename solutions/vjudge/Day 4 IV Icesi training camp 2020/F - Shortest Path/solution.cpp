#include <bits/stdc++.h>
#define endl '\n'
#define mt make_tuple
#define mp make_pair
using namespace std;

const int INF = 1e9;
const int MXN = 3010;
int n, m, k;
vector<int> g[MXN];
int dist[MXN][MXN], p[MXN][MXN];
set<tuple<int, int, int>> s;

int spfa() {
    memset(p, -1, sizeof p);
    queue<pair<int,int>> q;
    q.push(mp(0, 0));
    while(!q.empty()) {
        int u = q.front().first;
        int lst = q.front().second;
        q.pop();
        if(u == n - 1) return lst;
        for(auto & v : g[u]) {
            if(!s.count(mt(lst, u, v)) && !dist[u][v]) {
                p[u][v] = lst;
                dist[u][v] = dist[lst][u] + 1;
                q.push(mp(v, u));
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w; 
        u--, v--, w--;
        s.insert(mt(u, v, w));
    }
    int u = spfa();
    if(u != -1) {
        cout << dist[u][n - 1] << endl;
        int v = n - 1;
        vector<int> ans;
        while(v != 0) {
            ans.emplace_back(v + 1);
            int tmp = u;
            u = p[u][v];
            v = tmp;
        }
        ans.emplace_back(1);
        reverse(ans.begin(), ans.end());
        for(auto & u : ans) {
            cout << u << ' ';
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}