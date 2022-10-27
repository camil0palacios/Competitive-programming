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

const int Mxn = 2e5 + 5;
int n, k;
int x[Mxn], y[Mxn], t[Mxn];
bool vis[Mxn];
map<int,map<int,int>> px, py;
int mn;

void dfs(int i) {
    if(vis[i]) return;
    vis[i] = 1;
    mn = min(mn, t[i]);
    auto it = px[x[i]].lower_bound(y[i]);
    if(it != px[x[i]].begin()) {
        if((--it)->ft >= y[i]-k) dfs(it->sd);
    }
    it = px[x[i]].upper_bound(y[i]);
    if(it != px[x[i]].end()) {
        if(it->ft <= y[i]+k) dfs(it->sd);
    }

    it = py[y[i]].lower_bound(x[i]);
    if(it != py[y[i]].begin()) {
        if((--it)->ft >= x[i]-k) dfs(it->sd);
    }
    it = py[y[i]].upper_bound(x[i]);
    if(it != py[y[i]].end()) {
        if(it->ft <= x[i]+k) dfs(it->sd);
    }
}


int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        px.clear(), py.clear();
        fori(i,0,n) {
            cin >> x[i] >> y[i] >> t[i];
            px[x[i]][y[i]] = i;
            py[y[i]][x[i]] = i;
            vis[i] = 0;
        }
        vi v;
        fori(i,0,n) {
            if(!vis[i]) {
                mn = 1e9;
                dfs(i);
                v.eb(mn);
            }
        }
        sort(v.rbegin(), v.rend());
        int ans = sz(v)-1;
        fori(i,0,sz(v)) {
            ans = min(ans, max(i-1, v[i]));
        }
        cout << ans << endl;
    }
    return 0; 
}