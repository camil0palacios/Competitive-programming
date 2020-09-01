#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;
int mod;

mat mult(mat & a, mat & b){
    int n = a.size();
    mat x(n, vector<ll> (n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                x[i][j] = ( x[i][j] + (a[i][k]*b[k][j]) % mod) % mod;
            }
        }
    }
    return x;
}

mat be(ll n){
    mat ans = {{1,0,0},{0,1,0},{0,0,1}};
    mat v = {{1,1,1},{1,0,0},{0,0,1}};
    while(n > 0){
        if(n & 1)
            ans = mult(ans,v);
        v = mult(v,v);
        n >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, b;
    int c = 1;
    while(cin >> n >> b, n, b){
        mod = b;
        ll ans = 0;
        mat v = be(n-1);
        for(int i = 0; i < v.size(); i++){
            ans = (ans + v[0][i]) % mod;
        }
        cout << "Case " << c++ << ": " << n << " " << b << " " << ans << endl;
    }
    return 0;
}