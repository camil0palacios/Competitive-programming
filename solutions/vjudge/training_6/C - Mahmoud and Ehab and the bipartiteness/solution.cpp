#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
long long c1 = 0, c2 = 0;

void dfs(int u, int p, int c){
    if(c)c1++;
    else c2++;
    for(auto & to : g[u]){
        if(to != p){
            dfs(to, u, c^1);
        }
    }
}

int main(){
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,1,1);
    long long mmax = (c1*c2) - (n-1);
    cout << mmax << endl;
    return 0;
}