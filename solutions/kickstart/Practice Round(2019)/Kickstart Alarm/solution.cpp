#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long t, n, k, x1, y1, c, d, e1, e2, f;
    int ca = 1;
    cin >> t;
    while(t--){
        cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;
        vector<int> v(n), x(n+1), y(n+1);
        y[0] = x1; x[0] = y1;
        v[0] = (x1 + y1) % f;
        for(int i = 1; i < n; i++){
            x[i] = ((c*x[i-1])%f + (d*y[i-1])%f + e1)%f;
            y[i] = ((d*x[i-1])%f + (c*y[i-1])%f + e2)%f;
            v[i] = (x[i]+y[i])%f;
        }
        cout << "aqui fue" << endl;
        vector<vector<ll>> p(n, vector<ll> (k));
        for(int i = 0; i < n; i++){
            p[i][0] = i+1;
        }
        cout << "si paso --" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < k; j++){
                p[i][j] = (p[i][j-1]*(j+1))%f;
            }
        }
        cout << "si paso" << endl;
        ll res = 0;
        for(int i = 1; i < k; i++){
            for(int len = 1; len < n; len++){
                for(int j = 0; j + len - 1 < n; j++){
                    res += (v[j]+v[j+len-1]*p[i-1][j])%f;
                }
            }
        }
        cout << "Case #" << ca++ << ": " << res << endl;
    }
    return 0;
}