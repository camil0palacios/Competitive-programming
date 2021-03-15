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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 1e5 + 5;
bool vis[Mxn];
vi g[Mxn];

void dfs(int u, int & x) {
    vis[u] = 1, x++;
    for(auto & v : g[u]) {
        if(!vis[v]) dfs(v, x);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p;
    while(cin >> n >> p) {
        fori(i,0,n) {
            g[i].clear();
            vis[i] = 0;
        }
        fori(i,0,p) {
            int a, b;
            cin >> a >> b; 
            a--, b--;
            g[a].eb(b);
            g[b].eb(a);
        }
        vii ans;
        fori(i,0,n) {
            if(!vis[i]) {
                int x = 0;
                dfs(i, x);
                ans.eb(i,x);
            }
        }
        for(auto & i : ans) cout << i.ft+1 << ' ' << i.sd << endl;
    }
    return 0; 
}