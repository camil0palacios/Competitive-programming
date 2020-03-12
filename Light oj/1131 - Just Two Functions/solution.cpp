#include <bits/stdc++.h>
#define endl '\n'
#define long unsigned long long
using namespace std;

typedef vector<long> vl;
typedef vector<vl> mat;

long a[2], b[2], c[2];
long f[3], g[3], m;

mat mul(mat & a, mat & b){
    int n = (int)a.size();
    mat c(n, vl(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] = (c[i][j] + (a[i][k]*b[k][j]) % m ) % m;
            }
        }
    }
    return c;
}

void exp(int e){
    mat ans(6, vl(6));
    for(int i = 0; i < 6; i++)ans[i][i] = 1;
    mat x = { {a[0],b[0],0,0,0,c[0]}, {1,0,0,0,0,0}, {0,1,0,0,0,0},
              {0,0,c[1],a[1],b[1],0}, {0,0,0,1,0,0}, {0,0,0,0,1,0} };
    while(e){
        if(e & 1){
            ans = mul(ans, x);
        }
        x = mul(x,x);
        e >>= 1;
    }
    long fn = ( f[2]*ans[0][0] + f[1]*ans[0][1]+ f[0]*ans[0][2] + g[2]*ans[0][3] + g[1]*ans[0][4] + 
                g[0]*ans[0][5] ) % m;
    long gn = ( g[2]*ans[3][3] + g[1]*ans[3][4] + g[0]*ans[3][5] + f[2]*ans[3][0] + f[1]*ans[3][1] +
                f[0]*ans[3][2] ) % m; 
    cout << fn << ' ' << gn << endl;
}

void solve(){
    cin >> a[0] >> b[0] >> c[0];
    cin >> a[1] >> b[1] >> c[1];
    for(int i = 0; i < 3; i++)cin >> f[i];
    for(int i = 0; i < 3; i++)cin >> g[i];
    cin >> m;
    for(int i = 0; i < 2; i++){
        a[i] %= m, b[i] %= m, c[i] %= m;
    }
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(n <= 2)cout << f[n] % m << ' ' << g[n] % m << endl;
        else exp(n-2);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ':' << endl;
        solve();
    }
    return 0;
}