#include <bits/stdc++.h>
using namespace std;

int a[101], b[101], match[105], n, m;
vector<int> g[101];
bool vis[105];

bool dfs(int u){
    for(auto & i : g[u]){
        if(vis[i])continue;
        vis[i] = 1;
        if(match[i] == -1 || dfs(match[i])){
            match[i] = u;
            return 1;
        }
    }
    return 0;
}

void BPM(){
    memset(match, -1, sizeof match);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(g[i].empty())continue;
        memset(vis,0,sizeof vis);
        if(dfs(i))ans++;
    }
    cout << ans << endl;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> b[i];
        for(int j = 0; j < n; j++){
            if(b[i] % a[j] == 0){
                g[j].push_back(i);
            }
        }
    }
    BPM();
    for(int i = 0; i < 101; i++)g[i].clear();
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}