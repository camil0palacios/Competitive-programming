#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;
bool flag;
typedef vector<int> vi;
typedef vector<vi> graph;
vi cont;
vi col;

void bfs(graph & g, int x){
    queue<int> q;
    q.push(x);
    col[x] = 1;
    cont[1]++;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(auto & i : g[x]){
            if(col[i] == -1){
                q.push(i);
                col[i] = 1 - col[x];
                cont[col[i]]++;
            }
            else if(col[x] == col[i])
                flag = 1;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    while(cin >> t){
        while(t--){
            int n, m;
            cin >> n >> m;
            graph g(n);
            cont.assign(2,0);
            col.assign(n,-1);
            int p[n+1]; 
            p[0] = 1;
            for(int i = 1; i < n+1; i++)p[i] = (2 * p[i-1]) % mod;
            for(int i = 0; i < m; i++){
                int u,v; cin >> u >> v;
                g[--u].emplace_back(--v);
                g[v].emplace_back(u);
            }
            int ans = 1;
            for(int i = 0; i < n; i++){
                if(col[i] == -1){
                    flag = 0;
                    cont[0] = cont[1] = 0;
                    bfs(g,i);
                    if(flag){
                        ans = 0;
                        break;
                    }
                    int cur = (p[cont[0]] + p[cont[1]]) % mod;
                    ans = ((long long)ans * cur) % mod;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}