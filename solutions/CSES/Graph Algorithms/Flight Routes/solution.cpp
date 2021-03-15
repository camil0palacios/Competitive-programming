#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

typedef pair<int,int> ii;
typedef pair<ll,int> li;
const int MXN = 1e5 + 5;
vector<ii> g[MXN];
vector<ll> d[MXN];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c; u--, v--;
        g[u].emplace_back(v, c);
    }
    priority_queue<li, vector<li>, greater<li>> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        if(d[p.second].size() >= k) continue;
        d[p.second].emplace_back(p.first);
        for(auto & e : g[p.second]) {
            q.push({p.first + e.second, e.first});
        }
    }
    for(int i = 0; i < k; i++) {
        cout << d[n - 1][i] << ' ';
    }
    cout << endl;
    return 0; 
}