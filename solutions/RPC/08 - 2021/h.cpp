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

const int oo = 1e9;
const int Mxn = 1e5 + 5;
vi g[Mxn];
int p[Mxn], d[Mxn];

void bfs(int n, int s) {
    fori(i,0,n) d[i] = oo;
    queue<int> q;
    p[s] = -1, d[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto & v : g[u]) {
            if(d[u] + 1 < d[v]) {
                d[v] = d[u] + 1;
                q.push(v);  
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, s;
    cin >> n >> m >> s;
    fori(i,0,m) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    bfs(n, s);
    map<int, vi> ans;
    fori(i,0,n) {
        if(i == s) continue;
        if(d[i] == oo) ans[0].eb(i);
        else ans[d[i]].eb(i);
    }
    for(auto & p : ans) {
        cout << p.ft << ": ";
        bool ok = 0;
        for(auto & i : p.sd) {
            if(ok) cout << ' ';
            cout << i;
            ok = 1;
        }
        cout << endl;
    }
    return 0; 
}