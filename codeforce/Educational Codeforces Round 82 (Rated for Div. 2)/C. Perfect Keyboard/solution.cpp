#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool vis[26];
char ans[210];
int g[26][26], deg[26], idx;

void dfs(int u){
    vis[u] = 1;
    ans[idx++] = u + 'a';
    for(int i = 0; i < 26; i++){
        if(!vis[i] && g[u][i])dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        memset(deg, 0, sizeof deg);
        memset(vis, 0, sizeof vis);
        memset(g, 0, sizeof g);
        for(int i = 0; i < s.size() - 1; i++){
            int u = s[i] - 'a', v = s[i + 1] - 'a', x = g[u][v] ^ 1;
            deg[u] += x, deg[v] += x;
            g[u][v] = g[v][u] = 1;
        }
        bool ok = 1;
        for(int i = 0; i < 26; i++){
            if(deg[i] > 2){
                cout << "NO" << endl;
                ok = 0;
                break;
            }
        }
        if(!ok)continue;
        idx = 0;
        for(int i = 0; i < 26; i++){
            if(!vis[i] && deg[i] < 2)dfs(i);
        }
        cout << (idx == 26 ? "YES" : "NO") << endl;
        if(idx == 26){
            for(int i = 0; i < 26; i++){
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}