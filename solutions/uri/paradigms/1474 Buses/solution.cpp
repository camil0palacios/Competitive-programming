#include <bits/stdc++.h>
#define endl '\n'
#define ull unsigned long long
using namespace std;

typedef vector<ull> vi;
typedef vector<vi> mat;

const ull m6 = 1000000;

mat mul(mat & a, mat & b){
    int n = (int)a.size();
    mat c(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += (a[i][k] % m6 * b[k][j] % m6) % m6;
                c[i][j] %= m6;
            }
        }
    }
    return c;
}

ull n, k, l;

ull exp(ull b){
    mat id = { {1, 0}, {0, 1} };
    mat x = { {0, l % m6}, {1, k % m6} };
    while(b){
        if(b & 1)id = mul(id, x);
        x = mul(x, x);
        b >>= 1;
    }
    mat y = { {1, k % m6}, {0, 0} };
    y = mul(y, id);
    return y[0][0];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> k >> l){
        n /= 5;
        ull ans = exp(n);
        printf("%06lld\n", ans);
    }
    return 0;
}