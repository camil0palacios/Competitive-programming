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

const int N = 3e5 + 5;
vi g[N];

ii dfs(int u, int p) {
    ii dp;
    vii cdp;
    dp.ft = 0, dp.sd = 1;
    for(auto & v : g[u]) {
        if(p == v) continue;
        cdp.eb(dfs(v, u));
    }
    ii l = sz(cdp) ? cdp[0] : mp(0, 0);
    ii r = sz(cdp) >= 2 ? cdp[1] : mp(0, 0);
    dp.ft = max(l.ft + (r.sd ? r.sd - 1 : 0), r.ft + (l.sd ? l.sd - 1 : 0));
    dp.sd += l.sd + r.sd;
    return dp;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,0,n) g[i].clear();
        fori(i,0,n-1) {
            int u, v; cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }
        ii ans = dfs(1, 0);
        cout << ans.ft << endl;
    }
    return 0; 
}