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

const int Mxn = 7e5 + 5;
int n, m;
vi g[Mxn];
int mx[2], col[Mxn];
bool isb;

void dfs(int u, bool c) {
    col[u] = c;
    mx[c] += u < n;
    for(auto & v : g[u]) {
        if(col[v] == -1) dfs(v, c^1);
        else if(col[v] == c) isb = 0;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        fori(i,0,n+m) {
            g[i].clear();
            col[i] = -1;
        }
        int x = n;
        fori(i,0,m) {
            int u, v; string s;
            cin >> u >> v >> s;
            u--, v--;
            if(s[0] ==  'i') g[u].eb(v), g[v].eb(u);
            else {
                g[u].eb(x), g[x].eb(u);
                g[v].eb(x), g[x].eb(v);
                x++;
            }
        }
        isb = 1;
        int ans = 0;
        fori(i,0,n) {
            if(col[i] == -1) {
                mx[0] = mx[1] = 0;
                dfs(i, 0);
                ans += max(mx[0], mx[1]);
            }
        }
        if(isb) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0; 
}