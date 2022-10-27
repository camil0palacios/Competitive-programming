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

const int N = 2e5 + 5;
vi g[N];
int a[N], p[N], d[N];
bool vis[N];
int ans;

void dfs(int u) {
    if(a[u]) {
        int i = u;
        while(!vis[i]) {
            vis[i] = 1;
            i = p[i];
            ans += 2;
        }
    }
    for(auto & v : g[u]) {
        if(v == p[u]) continue;
        p[v] = u;
        d[v] = d[u] + 1;
        dfs(v);
    }
}


void clear(int n) {
    ans = 0;
    fore(i,0,n) {
        g[i].clear();
        a[i] = vis[i] = 0;
        d[i] = p[i] = 0;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k, x, y;
        cin >> n >> k;
        cin >> x >> y;
        clear(n);
        fori(i,0,k) {
            int k; cin >> k;
            a[k] = 1;
        }
        a[x] = a[y] = 1;
        fori(i,0,n-1) {
            int u, v;  cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }
        vis[x] = 1;
        dfs(x);
        cout << ans-d[y] << endl;
    }
    return 0; 
}