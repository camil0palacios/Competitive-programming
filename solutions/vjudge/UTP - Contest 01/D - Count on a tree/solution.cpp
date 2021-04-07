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
const int Lg = 18;
const int Sq = 318;
int a[Mxn];
vi g[Mxn];
int d[Mxn], st[Mxn][Lg];
int in[Mxn], out[Mxn];
int t[3*Mxn], ti = 0;

void dfs(int u = 0, int p = 0) {
    t[ti] = u;
    in[u] = ti++;
    for(auto & v : g[u]) {
        if(v == p) continue;
        d[v] = d[u] + 1;
        st[v][0] = u;
        fori(i,1,Lg) st[v][i] = st[st[v][i-1]][i-1];
        dfs(v, u);
    }
    t[ti] = u;
    out[u] = ti++;
}

int lca(int a, int b) {
    if(d[a] > d[b]) swap(a, b);
    forr(i,Lg-1,0) {
        if(d[a] - (1 << i) >= d[b]) {
            a = st[a][i];
        }
    }
    if(a == b) return a;
    forr(i,Lg-1,0) {
        if(st[a][i] != st[b][i]) {
            a = st[a][i];
            b = st[b][i];
        }
    }
    return st[a][0];
}

// struct Segment_tree {
//     vi st; int n;
//     Segment_tree(int n): n(n) { st.assign(4*n, 0); }
//     void update(int idx, int val) { update(1,0,n-1,idx,val); }
//     void update(int p, int l, int r, int idx, int val) {
//         if(idx < l || r < idx) return;
//         if(l == r) st[p] += val;
//         else {
//             int mid = (l + r) >> 1, left = p << 1, right = left + 1;
//             update(left, l, mid, idx, val);
//             update(right, mid+1, r, idx, val);
//             st[p] = st[left] + st[right];
//         }
//     }
//     int find(int k) { return find(1,0,n-1,k); }
//     int find(int p, int l, int r, int k) {
//         if(l == r) return l;
//         int mid = (l + r) >> 1, left = p << 1, right = left + 1;
//         if(k <= st[left]) return find(left, l, mid, k);
//         return find(right, mid+1, r, k - st[left]);
//     }
// };

// struct Node {
//     Node * l, * r;
//     ll val;
//     Node(): l(nullptr), r(nullptr), val(0) {}
// };

// Node * update(Node * p, ll l, ll r, ll idx, int val) {
//     if(!p) p = new Node();
//     if(idx < l || r < idx) return p;
//     if(l == r) p->val += val;
//     else {
//         ll mid = (l + r) >> 1;
//         p->l = update(p->l, l, mid, idx, val);
//         p->r = update(p->r, mid+1, r, idx, val);
//         p->val = p->l->val + p->r->val;
//     }
//     return p;
// }

// ll find(Node * p, ll l, ll r, int k) {
//     if(!p) p = new Node();
//     if(l == r) return l;
//     ll mid = (l + r) >> 1;
//     if(!p->l) p->l = new Node();
//     if(k <= p->l->val) return find(p->l, l, mid, k);
//     return find(p->r, mid+1, r, k - p->l->val);
// }

struct Query {
    int l, r, lc, k, i;
    Query() {}
    Query(int l, int r, int lc, int k, int i): l(l), r(r), lc(lc), k(k), i(i) {}
    bool operator<(const Query & q) { return mp(l/Sq, r) < mp(q.l/Sq, q.r); } 
};

bool vis[Mxn];
int ans[Mxn];
Segment_tree Sg(Mxn);
// const ll lim = 1e12;
// Node * root;

void add(int x) {
    if(!vis[x]) Sg.update(a[x], 1);
    else Sg.update(a[x], -1);
    vis[x] ^= 1;
    // if(!vis[x]) root = update(root, 0, lim, a[x], 1);
    // else root = update(root, 0, lim, a[x], -1);
    // vis[x] ^= 1;
}

void mos(vector<Query> & queries) {
    sort(all(queries));
    int l = 0, r = -1;
    for(auto & q : queries) {
        while(l < q.l) add(t[l++]);
        while(l > q.l) add(t[--l]);
        while(r < q.r) add(t[++r]);
        while(r > q.r) add(t[r--]);
        int u = t[l], v = t[r];
        if(q.lc != u && q.lc != v) add(q.lc);
        ans[q.i] = Sg.find(q.k);
        // ans[q.i] = find(root, 0, lim, q.k);
        if(q.lc != u && q.lc != v) add(q.lc);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) cin >> a[i];
    fori(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs();
    vector<Query> q;
    fori(i,0,m) {
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;
        int lc = lca(u, v);
        if(d[u] > d[v]) swap(u, v);
        q.eb(lc != u ? out[u] : in[u], in[v], lc, k, i);
    }
    mos(q);
    fori(i,0,m) cout << ans[i] << endl;
    return 0; 
}