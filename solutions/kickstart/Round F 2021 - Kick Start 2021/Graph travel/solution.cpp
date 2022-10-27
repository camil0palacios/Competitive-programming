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

const int Mxn = 16;
int n, m, k;
vi g[Mxn];
int l[Mxn], r[Mxn], a[Mxn];
ll dp[1 << Mxn];

ll get_sum(int msk) {
    ll ans = 0;
    fori(i,0,n) {
        if((msk >> i) & 1) ans += a[i];
    }
    return ans;
}

bool can(int msk, int i) {
    for(auto & v : g[i]) {
        if((msk >> v) & 1) return 1;
    }
    return 0;
}

ll go(int msk) {
    ll acc = get_sum(msk);
    if(acc == k) return 1;
    if(dp[msk] != -1) return dp[msk];
    ll ans = 0;
    fori(i,0,n) {
        if(!((msk >> i) & 1) && can(msk, i) 
            && acc + a[i] <= k && l[i] <= acc && acc <= r[i]) {
            ans += go(msk | (1 << i));
        }
    }
    return dp[msk] = ans;
} 

void solve() {
    cin >> n >> m >> k;
    fori(i,0,n) g[i].clear();
    fori(i,0,n) cin >> l[i] >> r[i] >> a[i];
    fori(i,0,m) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    fori(i,0,n) {
        ans += go(1 << i);
    }
    cout << ans << endl;
}


int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}