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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;
vi g[Mxn];
bool a[Mxn];
int in[Mxn], out[Mxn];

void dfs(int u, int p) {
    in[u] = a[u] ? 1 : -1;
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        in[u] += max(0, in[v]);
    }
}

void dfs2(int u, int p) {
    for(auto & v : g[u]) {
        if(v == p) continue;
        out[v] = max(0, out[u] + in[u] - (in[v] >= 0 ? in[v] : 0));
        dfs2(v, u);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    fori(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(0, 0);
    dfs2(0, 0);
    fori(i,0,n) {
        cout << in[i]+out[i] << ' ';
    }
    cout << endl;
    return 0; 
}