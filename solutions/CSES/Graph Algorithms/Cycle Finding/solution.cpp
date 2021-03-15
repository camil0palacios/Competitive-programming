#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

typedef pair<int,int> ii;
const int MXN = 2505;
const ll INF = 1e18;
ll dist[MXN];
vector<ii> g[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c; u--, v--;
        g[u].emplace_back(v, c);
    }
    for(int i = 0; i < n; i++) dist[i] = INF;
    vector<int> p(n, -1);
    dist[0] = 0;
    bool cycle = 0;
    int lst = -1;
    for(int i = 0; i < 2*n; i++) {
        bool ok = 0;
        lst = -1;
        for(int j = 0; j < n; j++) {
            for(auto & e : g[j]) {
                if(dist[j] + e.second < dist[e.first]) {
                    ok = 1;
                    dist[e.first] = dist[j] + e.second;
                    p[e.first] = j;
                    lst = e.first;
                }
            }
        }
        if(i >= n - 1 && ok) {
            cycle = 1;
            break;
        } 
    }
    if(cycle) {
        int y = lst;
        for(int i = 0; i < n; i++) 
            y = p[y];
        cout << "YES" << endl;
        vector<int> path;
        for(int i = y; ; i = p[i]) {
            path.emplace_back(i);
            if(i == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());
        for(auto & i : path) {
            cout << i + 1 << ' ';
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}