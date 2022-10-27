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

const int Mxn = 17;
int n;
vii g[Mxn];
int dp[1 << Mxn][Mxn];

unordered_set<int> get_edges(int msk) {
    unordered_set<int> s;   
    fori(i,0,n)
        if((msk >> i) & 1)
            for(auto & e : g[i]) s.insert(e.sd);
    return s;
}

int go(int msk, int u) {
    if(dp[msk][u] != -1) return dp[msk][u];
    int ans = 1;
    auto s = get_edges(msk);
    for(auto & e : g[u]) {
        int v = e.ft, id = e.sd;
        if(!s.count(id) && !((msk >> v) & 1)) {
            ans = max(ans, go(msk | (1 << u), v) + 1);
        }
    }
    return dp[msk][u] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, c;
    cin >> n >> c;
    fori(i,0,c) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v, i);
        g[v].eb(u, i);
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    fori(i,0,n) ans = max(ans, go(1 << i, i)); 
    cout << ans << endl;
    return 0; 
}