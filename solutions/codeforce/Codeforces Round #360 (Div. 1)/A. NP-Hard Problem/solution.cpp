#include <bits/stdc++.h>
using namespace std;

bool flag;
typedef vector<vector<int>> graph;
vector<int> a, b, col;

void dfs(graph & g, int u, int c){
    if(c)a.emplace_back(u);
    else b.emplace_back(u);
    col[u] = c;
    for(auto & i : g[u]){
        if(col[i] == -1)dfs(g,i,!c);
        if(col[u] == col[i])flag = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, u, v;
    while(cin >> n >> m){
        graph g(n);
        col.assign(n,-1);
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            v--, u--;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        flag = true;
        for(int i = 0; i < n; i++){
            if(col[i] == -1)dfs(g,i,0);
            if(!flag)break;
        }
        if(flag){
            cout << a.size() << endl;
            for(int i = 0; i < a.size(); i++){
                cout << a[i] + 1 << " ";
            }cout << endl;
            
            cout << b.size() << endl;
            for(int i = 0; i < b.size(); i++){
                cout << b[i] + 1<< " ";
            }cout << endl;
        }else cout << -1 << endl;
    }
    return 0;
}