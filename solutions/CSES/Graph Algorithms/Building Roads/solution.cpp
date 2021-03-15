#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int p[MXN];

int find(int a) {
    return a == p[a] ? a : p[a] = find(p[a]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        join(u, v);
    }
    for(int i = 0; i < n; i++) {
        find(i);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(p[i] == i) {
            ans.emplace_back(i);
        }
    }
    cout << ans.size() - 1 << endl;
    for(int i = 1; i < ans.size(); i++) {
        cout << ans[i - 1] + 1 << ' ' << ans[i] + 1 << endl;
    }
    return 0;
}