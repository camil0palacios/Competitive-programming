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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e5 + 5;
int n;
ll l[Mxn], r[Mxn];
vi g[Mxn];
ll dp[Mxn][2];

void dfs(int u = 0, int p = 0) {
    dp[u][0] = dp[u][1] = 0;
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0] + abs(l[u]-l[v]), dp[v][1] + abs(l[u]-r[v]));
        dp[u][1] += max(dp[v][0] + abs(r[u]-l[v]), dp[v][1] + abs(r[u]-r[v]));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fori(i,0,n) g[i].clear();
        fori(i,0,n) cin >> l[i] >> r[i];
        fori(i,0,n-1) {
            int u, v; cin >> u >> v;
            u--, v--;
            g[u].eb(v);
            g[v].eb(u);
        }
        dfs();
        cout << max(dp[0][0], dp[0][1]) << endl;
    }
    return 0; 
}