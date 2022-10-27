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

const int mod = 1e9 + 7;
const int Mxn = 101;
vi g[Mxn];
int cnt[Mxn];
ll dp[Mxn][Mxn];

ll cal_dp(int m, int k) {
    fore(i,0,m) fore(j,0,k) dp[i][j] = 0;
    dp[0][0] = 1;
    fore(i,1,m) {
        fore(j,0,k) {
            dp[i][j] = dp[i-1][j];
            if(j) dp[i][j] = (dp[i][j] + (dp[i-1][j-1]*cnt[i-1]) % mod) % mod;
        }
    }
    return dp[m][k];
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i,0,n) g[i].clear();
        fori(i,0,n-1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].eb(v);
            g[v].eb(u);
        }
        if(k == 2) {
            cout << n*(n-1)/2 << endl;
            continue;
        }
        ll ans = 0;
        fori(r,0,n) {
            int m = sz(g[r]);
            vector<ii> lay;
            vi vis(n+1);
            fori(i,0,m) {
                int u = g[r][i];
                lay.eb(u, i);
                cnt[i] = vis[u] = 1;
            }
            vis[r] = 1;
            while(sz(lay)) {
                ans = (ans + cal_dp(m, k)) % mod;
                vector<ii> nlay;
                for(auto & p : lay) {
                    cnt[p.sd]--;
                    for(auto & v : g[p.ft]) {
                        if(vis[v]) continue;
                        nlay.eb(v, p.sd);
                        cnt[p.sd]++;
                        vis[v] = 1;
                    }
                }
                lay = nlay;
            }
        }
        cout << ans << endl;
    }
    return 0; 
}