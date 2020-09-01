#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> graph;
vector<bool> used;
set<int> s;
long long mmin, mmax;

void dfs(graph & g, int n){
    used[n] = 1;
    mmin = min(mmin, (long long)g[n].size());
    mmax = max(mmax, (long long)g[n].size());
    s.insert(n);
    for(auto & i: g[n]){
        if(!used[i])dfs(g,i);
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m){
        long long a, b;
        cin >> a >> b;
        graph g(n);
        used.assign(n,0);
        for(int i = 0; i < m; i++){
            int u, v; 
            cin >> u >> v;
            u--, v--;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        int ans = 0;
        mmin = 999999, mmax = 0;
        for(int i = 0; i < n; i++){
            if(!used[i]){
                dfs(g,i);
                long long u = a*mmin, _u = b*mmax;
                for(auto & j : s){
                    if(u < (long long)g[j].size() && (long long)g[j].size() < _u)ans++;
                }
                mmin = 999999, mmax = 0;
                s.clear();
            }
        }
        cout << ans << endl;
    }
    return 0;
}