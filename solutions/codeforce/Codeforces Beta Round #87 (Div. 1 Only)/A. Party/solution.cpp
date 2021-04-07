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

const int Mxn = 2020;
bool vis[Mxn];
vi g[Mxn];
set<int> s;

void dfs(int u, int p = 0, int d = 0) {
    vis[u] = 1;
    s.insert(d);
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs(v, u, d+1);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,1,n) {
        int u; cin >> u;
        if(u == -1) continue;
        g[u].eb(i);
    }
    fore(i,1,n) {
        if(!vis[i]) dfs(i);
    }
    cout << sz(s) << endl;
    return 0; 
}