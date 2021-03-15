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

const int Mxn = 110;
int n;
int a[Mxn], d[Mxn];

void dfs(int l, int r, int depth) {
    int v = 0, mx = 0;
    for(int i = l; i <= r; i++) {
        if(mx < a[i]) v = i, mx = a[i];
    }
    d[v] = depth;
    if(l < r) {
        if(l <= v-1) dfs(l, v-1, depth+1);
        if(v+1 <= r) dfs(v+1, r, depth+1);
    }
}

void solve() {
    cin >> n;
    fori(i,0,n) cin >> a[i];
    dfs(0, n-1, 0);
    fori(i,0,n) cout << d[i] << ' ';
    cout << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}