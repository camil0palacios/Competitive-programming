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
int c[Mxn];
int a[Mxn], it;
int ans[Mxn];
int bit[Mxn];

void upd(int i, int val) {
    i++;
    for(; i < Mxn; i += i & -i) bit[i] += val; 
}
int sum(int i) {
    int ans = 0;
    for(; i; i -= i & -i) ans += bit[i];
    return ans;
}
int qry(int l, int r) {
    return sum(r+1) - sum(l);
}

struct Query {
    int l, r, u;
    Query(){}
    Query(int l, int r, int u): l(l), r(r), u(u) {}
};

vector<Query> q;

int dfs(int u = 0, int p = 0) {
    a[it] = c[u];
    int who = it++, tam = 1;
    for(auto & v : g[u]) {
        if(v == p) continue;
        tam += dfs(v, u);
    }
    q.eb(who, who+tam-1, u);
    return tam;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> c[i];
    fori(i,1,n) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs();
    sort(all(q), [](Query q1, Query q2) { return q1.r < q2.r; });
    int j = 0;
    map<int,int> lst;
    fori(i,0,n) {
        if(lst.count(a[i])) upd(lst[a[i]], -1);
        lst[a[i]] = i;
        upd(i, 1);
        while(j < sz(q) && q[j].r == i) {
            ans[q[j].u] = qry(q[j].l, q[j].r);
            j++;
        }
    }
    fori(i,0,n) cout << ans[i] << ' ';
    cout << endl;
    return 0; 
}