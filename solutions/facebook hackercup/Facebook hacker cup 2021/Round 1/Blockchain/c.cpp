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
const int Mxn = 8e5 + 5;
int n;
ii edges[Mxn];
vii edges_w[21];
int p[Mxn];
ll szn[Mxn];

int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
ll join(int a, int b, int w) {
    ll ans = 0;
    a = find(a), b = find(b);
    if(a != b) {
        ans = ((szn[a] * szn[b]) % mod  * w) % mod;
        szn[a] += szn[b];
        p[b] = a;
    }
    return ans;
}

ll get_ans() {
    fore(i,1,n) p[i] = i, szn[i] = 1;
    ll ans = 0;
    forr(i,20,1) {
        for(auto & e : edges_w[i]) {
            ans = (ans + join(e.ft, e.sd, i)) % mod;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    fore(i,1,20) edges_w[i].clear();
    fori(i,0,n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        edges_w[w].eb(u, v);
        edges[i] = mp(u, v);
    }
    ll par = get_ans();
    fore(i,1,n) p[i] = i, szn[i] = 1;
    ll ans = 1;
    forr(i,20,1) {
        for(auto & e : edges_w[i]) {
            ll x = (par - join(e.ft, e.sd, i) + mod) % mod;
            ans = (ans * x) % mod; 
        }
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