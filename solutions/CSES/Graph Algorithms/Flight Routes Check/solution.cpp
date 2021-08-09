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
bool vis[Mxn];
int head[Mxn];
stack<int> s;

void dfs(int u) {
    vis[u] = 1;
    for(auto & v : g[u])
        if(!vis[v]) dfs(v);
    s.push(u);
}

void dfs2(int u, int h) {
    vis[u] = 1; head[u] = h; 
    for(auto & v : t[u])
        if(!vis[v]) dfs2(v, h);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        t[v].eb(u);
    }
    fori(i,0,n) if(!vis[i]) dfs(i);
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        if(!vis[u]) {
            dfs2(u, u);
            cnt++;
        }
    }
    if(cnt == 1) cout << "YES" << endl;
    else {
        vi ans;
        fori(i,0,n) {
            for(auto & v : g[i]) {
                if(head[i] != head[v]) {
                    ans.eb(v), ans.eb(i);
                    goto res;
                }
            }
        }
        if(!sz(ans)) {
            set<int> s;
            fori(i,0,n) {
                if(s.count(head[i])) continue; 
                s.insert(head[i]);
                ans.eb(head[i]);
                if(sz(ans) >= 2) break;
            }
        }
        res:
        cout << "NO" << endl;
        cout << ans[0]+1 << ' ' << ans[1]+1 << endl;
    }
    return 0; 
}