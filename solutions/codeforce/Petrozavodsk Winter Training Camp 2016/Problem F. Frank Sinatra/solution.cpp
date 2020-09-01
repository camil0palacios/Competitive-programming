#include <bits/stdc++.h>
#define endl '\n'
#define s second
#define f first
#define mp make_pair
using namespace std;

const int NMAX = 1e5 + 5;
int const bsize = 320;
int n, m;

bool vis[NMAX];
int frq[NMAX], sum[NMAX], val[NMAX];
int tin[NMAX], tout[NMAX], flat[NMAX << 1];
int cur = 0;

typedef pair<int,int> edge;
vector<edge> g[NMAX];

struct query{
    int l, r, id;
    query(){}
    query(int _l, int _r, int _id){
        l = _l, r = _r, id =_id;
    }
    bool operator<(const query & q)const{
        //return mp(l/bsize, r) < mp(q.l/bsize, q.r);
        if(l/bsize != q.l/bsize){
            return mp(l/bsize, r) < mp(q.l/bsize, q.r);
        }
        return (l/bsize & 1) ? (r < q.r) : (r > q.r);
    }
};

void dfs(int u, int p){
    tin[u] = ++cur;
    flat[cur] = u;
    for(auto & to : g[u]){
        if(to.f == p)continue;
        val[to.f] = to.s;
        dfs(to.f, u);
    }
    tout[u] = ++cur;
    flat[cur] = u;
}

void check(int u){
    if(val[u] > n)return;
    if(vis[u] && --frq[val[u]] == 0){
        sum[val[u]/bsize]--;
    }
    else if(!vis[u] && frq[val[u]]++ == 0){
        sum[val[u]/bsize]++;
    }
    vis[u] ^= 1;
}

void mos_algorithm(vector<query> & Q){
    vector<int> ans(m);
    sort(Q.begin(), Q.end());
    int l = Q[0].l, r = Q[0].l - 1;
    for(auto & q : Q){
        while(l < q.l)check(flat[l++]);
        while(l > q.l)check(flat[--l]);
        while(r < q.r)check(flat[++r]);
        while(r > q.r)check(flat[r--]);
        int i;
        for(i = 0; sum[i] == bsize; i++); //find by block sqrt(n) size
        for(i *= bsize; frq[i]; i++); //find in the block
        ans[q.id] = i;
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < n-1; i++){
        int w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(mp(v,w));
        g[v].emplace_back(mp(u,w));
    }
    dfs(0,0);
    vector<query> Q;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--,v--;
        if(tin[u] > tin[v])swap(u,v);
        Q.push_back(query(tin[u] + 1, tin[v], i));
    }
    mos_algorithm(Q);
    return 0;
}