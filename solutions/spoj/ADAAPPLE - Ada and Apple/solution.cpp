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

const int Mxn = 3e5 + 5;
const int Lg = 19;
string s;
int sp[Mxn][Lg], depth[Mxn];
int pr[Mxn], dp[Mxn], heavy[Mxn], head[Mxn], wh[Mxn], it;
int st[Mxn*4][2], pos[Mxn];
vi g[Mxn];

void bld(int p, int l, int r) {
    if(l == r) st[p][0] = st[p][1] = pos[l];
    else {
        int mid = (l + r) >> 1, left = p << 1, right = left+1;
        bld(left, l, mid);
        bld(right, mid+1, r);
        st[p][0] = min(st[left][0], st[right][0]);
        st[p][1] = max(st[left][1], st[right][1]);
    }
}
void upd(int p, int l, int r, int idx, int val) {
    if(idx < l || r < idx) return;
    if(l == r) st[p][0] = st[p][1] = val;
    else {
        int mid = (l + r) >> 1, left = p << 1, right = left+1;
        upd(left, l, mid, idx, val);
        upd(right, mid+1, r, idx, val);
        st[p][0] = min(st[left][0], st[right][0]);
        st[p][1] = max(st[left][1], st[right][1]);        
    }
}
ii qry(int p, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return {1e9, 0};
    if(ql <= l && r <= qr) return {st[p][0], st[p][1]};
    int mid = (l + r) >> 1, left = p << 1, right = left+1;
    auto p1 = qry(left, l, mid, ql, qr);
    auto p2 = qry(right, mid+1, r, ql, qr);
    return {min(p1.ft,p2.ft), max(p1.sd, p2.sd)};
}

void dfs(int u) {
    dp[u] = 1;
    int mx = 0;
    for(auto & v : g[u]) {
        if(v == pr[u]) continue;
        depth[v] = depth[u]+1;
        sp[v][0] = pr[v] = u;
        fori(i,1,Lg) sp[v][i] = sp[sp[v][i-1]][i-1];
        dfs(v);
        dp[u] += dp[v];
        if(dp[v] > mx) {
            mx = dp[v];
            heavy[u] = v;
        }
    }
}

void build(int u, int h) {
    head[u] = h, wh[u] = it, pos[it] = s[u]-'0';
    it++;
    if(heavy[u] != -1) build(heavy[u], h);
    for(auto & v : g[u])
        if(v != pr[u] && v != heavy[u]) build(v, v);
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    forr(i,Lg-1,0) {
        if(depth[u] - (1 << i) >= depth[v]) u = sp[u][i];
    }
    if(u == v) return u;
    forr(i,Lg-1,0) {
        if(sp[u][i] != sp[v][i]) {
            u = sp[u][i];
            v = sp[v][i];
        }
    }
    return sp[u][0];
}

ii qry_hld(int u, int v) {
    ii ans = {1e9, 0};
    for(; head[u] != head[v]; u = pr[head[u]]) {
        auto p = qry(1, 0, it, wh[head[u]], wh[u]);
        ans = {min(ans.ft, p.ft), max(ans.sd, p.sd)};
    }
    auto p = qry(1, 0, it, wh[v], wh[u]);
    ans = {min(ans.ft, p.ft), max(ans.sd, p.sd)};
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    
    cin >> n >> q >> s;
    fori(i,1,n) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    memset(heavy, -1, sizeof heavy);
    dfs(0);
    build(0, 0);
    bld(1, 0, it);
    fori(i,0,q) {
        int t;
        cin >> t;
        if(!t) {
            int u; 
            cin >> u;
            upd(1, 0, it, wh[u], (s[u]-'0')^1);
            s[u] = char((s[u]-'0')^1 + '0');
        } else {
            int u, v;
            cin >> u >> v;
            int lc = lca(u, v);
            auto p = qry_hld(u, lc);
            auto q = qry_hld(v, lc);
            ii ans = {min(p.ft, q.ft), max(p.sd, q.sd)};
            cout << (ans.ft == ans.sd ? "YES" : "NO") << endl;
        }
    } 
    return 0; 
}