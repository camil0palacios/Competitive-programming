#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;
const int MXN = 5050;
int n;
int a[MXN];
bool vis[MXN];
vector<ii> e;

void dfs(int u) {
    vis[u] = 1;
    for(int i = 0; i < n; i++) {
        if(!vis[i] && a[u] != a[i]) {
            e.emplace_back(u + 1, i + 1);
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) vis[i] = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        e.clear();
        dfs(0);
        if(e.size() == n - 1) {
            cout << "YES" << endl;
            for(auto & i : e) {
                cout << i.first << ' ' << i.second << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}