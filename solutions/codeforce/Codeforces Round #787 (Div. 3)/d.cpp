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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 2e5 + 5;
vi g[N], path[N];
int cp;

void dfs(int u, int p) {
    path[p].eb(u);
    bool ok = 0;
    for(auto & v : g[u]) {
        if(ok) dfs(v, ++cp);
        else dfs(v, p);
        ok = 1;
    }
}

void clear(int n) {
    cp = 0;
    fore(i,0,n) {
        g[i].clear();
        path[i].clear();
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        clear(n);
        int r;
        fore(i,1,n) {
            int p; cin >> p;
            if(p != i) g[p].eb(i);
            else r = i;
        }
        dfs(r, 0);
        cout << cp+1 << endl;
        fori(i,0,cp+1) {
            cout << sz(path[i]) << endl;
            for(auto v : path[i]) cout << v << ' ';
            cout << endl;
        }
    }
    return 0; 
}