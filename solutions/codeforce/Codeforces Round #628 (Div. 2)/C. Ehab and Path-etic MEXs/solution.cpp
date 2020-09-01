#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
vector<int> g[MAXN];
int ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].emplace_back(i);
        g[v].emplace_back(i);
    }
    for(int i = 0; i < n; i++) {
        ans[i] = -1;
    }
    pii mx(0, 0);
    for(int i = 0; i < n; i++) {
        mx = max(mx, mp((int)g[i].size(), i));
    }
    int cur = 0;
    for(auto & i : g[mx.second]){
        ans[i] = cur++;
    }
    for(int i = 0; i < n - 1; i++) {
        if(ans[i] == -1)ans[i] = cur++;
        cout << ans[i] << endl;
    }
    return 0;
}