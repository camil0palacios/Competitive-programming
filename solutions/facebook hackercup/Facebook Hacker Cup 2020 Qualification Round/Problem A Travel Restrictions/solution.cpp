#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 55;
int n;
char in[MXN], out[MXN];
bool vis[MXN];
vector<int> g[MXN];

void dfs(int u) {
    vis[u] = 1;
    for(auto & v : g[u]) {
        if(!vis[v]) dfs(v);
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) g[i].clear();
    for(int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> out[i];
    }
    for(int i = 0; i < n; i++) {
        if(out[i] == 'Y') {
            if(i == 0 && in[i + 1] == 'Y') g[i].emplace_back(i + 1);
            else if(i == n - 1 && in[i - 1] == 'Y') g[i].emplace_back(i - 1);
            else {
                if(in[i + 1] == 'Y') g[i].emplace_back(i + 1);
                if(in[i - 1] == 'Y') g[i].emplace_back(i - 1);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) vis[j] = 0;
        dfs(i);
        for(int j = 0; j < n; j++) {
            cout << (vis[j] == 1 ? 'Y' : 'N');   
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ":" << endl;
        solve();
    }
    return 0;
}