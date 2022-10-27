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

const int oo = 1e9;
const int Mxn = 2e5 + 5;
int n, k;
vi g[Mxn];
int x[Mxn];
int d[2][Mxn];

void bfs(int s) {
    queue<int> q;
    if(s) q.push(0), d[s][0] = 0;
    else fori(i,0,k) q.push(x[i]), d[s][x[i]] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto & v : g[u]) {
            if(d[s][u]+1 < d[s][v]) {
                d[s][v] = d[s][u]+1;
                q.push(v);
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        fori(i,0,n) {
            d[0][i] = d[1][i] = oo;
            g[i].clear();
        }
        fori(i,0,k) cin >> x[i], x[i]--;
        fori(i,0,n-1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].eb(v);
            g[v].eb(u);
        }
        bfs(0);
        bfs(1);
        bool ok = 0;
        fori(i,0,n) {
            if(sz(g[i]) == 1 && i != 0) {
                ok |= d[1][i] < d[0][i];
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}