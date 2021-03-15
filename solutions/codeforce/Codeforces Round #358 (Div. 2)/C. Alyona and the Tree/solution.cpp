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
int a[Mxn];
vii g[Mxn];
int ans;

void dfs(int u, ll d) {
    if(d > a[u]) return;
    ans++;
    for(auto & e : g[u]) {
        int v = e.ft, w = e.sd;
        dfs(v, max(0ll, d+w));
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,1,n) cin >> a[i];
    fori(i,1,n) {
        int v, c;
        cin >> v >> c;
        g[v].eb(i+1, c);
    }
    dfs(1,0);
    cout << n-ans << endl;
    return 0;
}