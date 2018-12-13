#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

struct nodo{
    ll p, w;
    nodo(){}
    nodo(ll _p, ll _w): p(_p), w(_w){}
};

typedef vector<nodo> vn;
ll dp[51][101];

ll ks(vn &v, int idx, int k){
    if(idx == v.size() || k == 0)return 0;
    if(dp[idx][k] != -1)return dp[idx][k];
    ll ans = 0;
    if(v[idx].w > k)ans = ks(v, idx + 1, k);
    else ans = max(ks(v, idx + 1, k - v[idx].w) + v[idx].p, ks(v, idx + 1, k));
    return dp[idx][k] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n, k, r;
        cin >> n;
        vector<nodo> v(n);
        for(auto &i : v)cin >> i.p >> i.w;
        cin >> k >> r;
        memset(dp, -1, sizeof dp);
        ll ans = ks(v,0,k);
        if(ans >= r)cout << "Missao completada com sucesso" << endl;
        else cout << "Falha na missao" << endl;
    }
    return 0;
}