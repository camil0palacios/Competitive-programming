#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e6 + 5;
int w[MXN], cnt[MXN];
vector<pair<int,int>> g[MXN];

void dfs(int u, int edge = -1) {
    if(g[u].size() == 1) cnt[edge] = 1;
    for(auto & to : g[u]) {
        int v = to.first, id = to.second;
        if(id == edge) continue;
        dfs(v, id);
        if(edge != -1) cnt[edge] += cnt[id];
    }   
}

ll diff(int i) {
    return w[i] * 1LL * cnt[i] - (w[i] / 2) * 1LL * cnt[i]; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; ll S;
        cin >> n >> S;
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v >> w[i];
            u--, v--;
            g[u].emplace_back(v, i);
            g[v].emplace_back(u, i);
            cnt[i] = 0;
        }   
        dfs(0);
        priority_queue<pair<ll, int>> q;
        ll cur = 0;
        for(int i = 0; i < n - 1; i++) {
            cur += 1LL * w[i] * cnt[i];
            q.emplace(diff(i), i);
        }   
        int ans = 0;
        while(cur > S) {
            int i = q.top().second;
            q.pop();
            cur -= diff(i);
            w[i] /= 2;
            q.emplace(diff(i), i);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}