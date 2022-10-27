#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 1e5 + 5;
vi g[N];
int sz[N];

void dfs(int u, int p = -1) {
    sz[u] = 1;
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        fore(i,0,n) g[i].clear(), sz[i] = 0;
        fori(i,1,n) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].eb(v);
            g[v].eb(u);
        }
        x--;
        dfs(x);
        if(sz(g[x]) <= 1) cout << "Ayush" << endl;
        else cout << (((sz[x]-2) % 2 == 0) ? "Ayush" : "Ashish") << endl;
    }
    return 0; 
}