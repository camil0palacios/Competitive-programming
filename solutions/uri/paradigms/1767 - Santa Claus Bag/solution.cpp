#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

struct nodo{
    ll t, w;  //toys and weight
    nodo(){}
    nodo(ll _t, ll _w): t(_t), w(_w){}
};

struct pack{
    ll a, b, c;
    pack(){}
    pack(ll _a, ll _b, ll _c): a(_a), b(_b), c(_c){}
};

typedef vector<nodo> vn;
pack dp[100][51];

pack ks(vn &v, int idx = 0, int k = 50){
    if(idx == v.size() || k == 0)return pack(0, (ll)k, 0);
    if(dp[idx][k].a != -1)return dp[idx][k];
    pack ans = ks(v, idx + 1, k);
    if(v[idx].w <= (ll)k){
        pack par1 = ks(v, idx + 1, k - v[idx].w);
        par1.a += v[idx].t;
        par1.c += 1;
        if(par1.a > ans.a)ans = par1;
    }
    return dp[idx][k] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<nodo> v(n);
        for(auto &i : v)cin >> i.t >> i.w;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 51; j++){
                dp[i][j] = pack(-1,-1,-1);       
            }
        }
        pack ans = ks(v);
        cout << ans.a << " brinquedos" << endl;
        cout << "Peso: " << 50 - ans.b << " kg" << endl;
        cout << "sobra(m) "<< n - ans.c << " pacote(s)" << endl << endl;
    }
    return 0;
}