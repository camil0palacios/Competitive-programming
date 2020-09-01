#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int const NM = 1e5 + 5;
vector<int> g[NM];
int col[NM], cur_col;
bool ok;

void dfs(int u, int p){
    ok = (ok && (cur_col == col[u]));
    for(auto & to: g[u]){
        if(to == p)continue;
        dfs(to, u);
    }
}

bool solve(int u){
    bool ans = 1;
    for(auto & to: g[u]){
        cur_col = col[to];
        ok = 1;
        dfs(to, u);
        ans = ans && ok;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++){
        cin >> col[i];
    }
    int root1 = -1, root2 = -1;
    for(int i = 1; i <= n; i++){
        for(auto & j : g[i]){
            if(col[i] != col[j]){
                root1 = i;
                root2 = j;
                //break;
            }
        }
    }
    if(root1 == -1){
        cout << "YES" << endl;
        cout << 2 << endl;
        return 0;
    }
    int res1 = solve(root1);
    int res2 = solve(root2);
    if(res1){
        cout << "YES" << endl;
        cout << root1 << endl;
    }
    else if(res2){
        cout << "YES" << endl;
        cout << root2 << endl;
    }
    else cout << "NO" << endl;
    return 0;
}