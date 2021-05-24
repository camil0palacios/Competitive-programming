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
int c[Mxn];
vi g[Mxn];
set<int> s[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) cin >> c[i];
    fori(i,0,m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    fori(i,0,n) {
        for(auto v : g[i])
            if(c[v] != c[i]) s[c[i]].insert(c[v]);
    }
    int ans = 0, mx = 0;
    fori(i,0,Mxn) {
        if(mx < sz(s[i])) {
            mx = sz(s[i]);
            ans = i;
        }
    }
    if(ans == 0) { 
        ans = 1e9;
        fori(i,0,n) ans = min(ans, c[i]);
    }
    cout << ans << endl;
    return 0; 
}