#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> graph;
vector<bool> used;

int main(){

    int n, m;
    while(cin >> n >> m){
        graph g(n);
        used.assign(n,0);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> ans;
        used[0] = 1;
        q.push(0);
        while(!q.empty()){
            int u = q.top();
            ans.emplace_back(u);
            q.pop();
            for(auto & v : g[u]){
                if(!used[v]){
                    q.push(v);
                    used[v] = 1;
                }
            }
        }

        for(auto & i : ans)
            cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}