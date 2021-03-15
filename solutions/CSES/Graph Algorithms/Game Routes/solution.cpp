#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int mod = 1e9 + 7;
const int Mxn = 1e5 + 5;
int n, m;
vi g[Mxn];
int dp[Mxn];

void add(int & a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

bool isleaf(int u) { return sz(g[u]) == 0; }

int dfs(int u) {
    if(isleaf(u)) return u == n;
    if(dp[u] != -1) return dp[u];
    int ans = 0;
    for(auto & v : g[u]) {
        add(ans, dfs(v));
    }
    return dp[u] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fori(i,0,m) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(1) << endl;
    return 0; 
}