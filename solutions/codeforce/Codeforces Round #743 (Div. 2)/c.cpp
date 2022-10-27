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

const int Mxn = 2e5 + 5;
vi g[Mxn];
int col[Mxn];
int dp[Mxn];

bool cycle(int u) {
    col[u] = 1;
    for(auto & v : g[u]) {
        if(col[v] == 0 && cycle(v)) return 1;
        else if(col[v] == 1) return 1;
    }
    col[u] = 2;
    return 0;
}

int go(int u) {
    if(dp[u] != -1) return dp[u];
    int ans = 0;
    for(auto & v : g[u]) {
        ans = max(ans, go(v) + (u > v));
    }
    return dp[u] = ans;
}

void solve() {
    int n;
    cin >> n;
    fori(i,0,n) g[i].clear(), col[i] = 0;
    fori(i,0,n) {
        int k;
        cin >> k;
        fori(j,0,k) {
            int v; cin >> v; v--;
            g[v].eb(i);
        }
    }
    bool has_cycle = 0;
    fori(i,0,n) if(cycle(i)) {
        has_cycle = 1;
        break;
    }
    if(has_cycle) cout << -1 << endl;
    else {
        fori(i,0,n) dp[i] = -1;
        int ans = 0;
        fori(i,0,n) ans = max(ans, go(i) + 1);
        cout << ans << endl;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}