#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
const int MXN = 2e5 + 5;
int n;
vector<int> g[MXN];
int in[MXN], out[MXN];

void dfs1(int u, int p = -1) {
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs1(v, u);
        in[u] = max(in[u], in[v] + 1);
    }
}

// void dfs2(int u, int p = -1, int pd = 0) {
//     out[u] = max(in[u], pd);
//     vector<ii> w;
//     w.emplace_back(pd, -1);
//     for(auto & v : g[u]) {
//         if(v == p) continue;
//         w.emplace_back(in[v] + 1, v);
//     }
//     w.emplace_back(0, -1);
//     sort(all(w), greater<ii>());
//     for(auto & v : g[u]) {
//         if(v == p) continue;
//         dfs2(v, u, w[0].second == v ? w[1].first + 1 : w[0].first + 1);
//     }
// }

void dfs2(int u, int p = -1) {
    ii mx1 = {out[u], u}, mx2 = {0, -1};
    for(auto & v: g[u]) {
        if(v == p) continue;
        ii x = {in[v] + 1, v};
        if(mx1.ft < x.ft) {
            ii tmp = mx1;
            mx1 = x;
            mx2 = tmp;
        }
        else if(mx2.ft < x.ft) {
            mx2 = x;
        }
    }
    for(auto & v: g[u]) {
        if(v == p) continue;
        out[v] = mx1.sd == v ? mx2.ft + 1 : mx1.ft + 1;
        dfs2(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs1(0);
    dfs2(0);
    for(int i = 0; i < n; i++) {
        if(i != 0) cout << ' ';
        cout << max(in[i], out[i]);
    }
    cout << endl;
    return 0;
}