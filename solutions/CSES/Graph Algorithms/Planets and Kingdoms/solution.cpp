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
vi g[Mxn], t[Mxn];

// dont forget graph g and transpose t
int cmp[Mxn];
bool vis[Mxn];
stack<int> st;

void dfs1(int u) {
    vis[u] = 1;
    for(auto & v : g[u]) if(!vis[v]) dfs1(v);
    st.push(u);
}

void dfs2(int u, int c) {
    vis[u] = 1, cmp[u] = c;
    for(auto & v : t[u]) if(!vis[v]) dfs2(v, c);
}

int kosarajus(int n) {
    memset(vis, 0, sizeof vis);
    fori(i,0,n) if(!vis[i]) dfs1(i);
    memset(vis, 0, sizeof vis);
    int c = 0;
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        if(!vis[u]) dfs2(u, c++);
    }
    return c;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,m)  {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        t[v].eb(u);
    }
    int k = kosarajus(n);
    cout << k << endl;
    fori(i,0,n) {
        cout << cmp[i]+1 << ' ';
    }
    cout << endl;
    return 0; 
}