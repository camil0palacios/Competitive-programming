#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int Mxn = 1e5 + 5;
int t[Mxn], a[Mxn]; 
vi g[Mxn];
int deg[Mxn];

int dfs(int u, int d) {
    if(g[u].size() && deg[g[u][0]] < 2) {
        d = dfs(g[u][0], d + 1);
    }
    return d;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,1,n) {
        cin >> t[i];
    }
    fore(i,1,n) {
        cin >> a[i];
        if(a[i]) {
            g[i].eb(a[i]);
            deg[a[i]]++;
        }
    }
    int mx = 0, u = 0;
    fore(i,1,n) {
        if(t[i]) {
            int d = dfs(i, 1);
            if(mx < d) {
                mx = d;
                u = i;
            }
        }
    }
    cout << mx << endl;
    vi ans;
    while(mx) {
        ans.eb(u);
        if(g[u].size()) u = g[u][0];
        mx--;
    }
    reverse(all(ans));
    for(auto & i : ans) {
        cout << i << ' ';
    }
    cout << endl;
    return 0; 
}