#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const int MXN = 2e5 + 5;
vector<int> g[MXN];
int cycle;
int col[MXN], inCycle[MXN];

bool dfs(int u, int p) {
    col[u] = 1;
    for(auto & v: g[u]) {
        if(v == p) continue;
        if(!col[v] && dfs(v, u)) {
            if(cycle != -1) inCycle[u] = 1;
            if(cycle == u) cycle = -1;
            return 1;
        } 
        else if(col[v] == 1) {
            cycle = v;
            inCycle[u] = 1;
            return 1;
        }
    }
    col[u] = 2;
    return 0;
}

int p[MXN], sz[MXN];
bool proccess[MXN];

int find(int a){ return a == p[a] ? a : p[a] = find(p[a]); }
void join(int a, int b) { a = find(a); b = find(b); if(a != b) { p[b] = a; sz[a] += sz[b]; } }

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) { 
        g[i].clear();
        inCycle[i] = col[i] = proccess[i] = 0;
        p[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(0,0);
    for(int i = 0; i < n; i++) {
        for(auto & v : g[i]) {
            if(!inCycle[v]) {
                join(i, v);
            }
        }
    }
    ll ans = ((ll)n*(n-1)/2)*2LL;
    for(int i = 0; i < n; i++) {
        int id = find(i);
        if(proccess[id]) continue;
        proccess[id] = 1;
        ans -= (ll)sz[id]*(sz[id]-1)/2;
    }
    cout << ans << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
}