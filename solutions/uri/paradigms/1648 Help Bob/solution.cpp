#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const double INF = 1e12;
const int Mxn = 16;
int m;
double p[Mxn], a[Mxn], d[Mxn][Mxn], dp[1 << Mxn];

void reset() {
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < m; j++)
           d[i][j] = 1.0;
    for(int i = 0; i < (1 << m); i++) dp[i] = INF;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(4);
    while(cin >> m, m) {
        reset();
        for(int i = 0; i < m; i++) {
            int n;
            cin >> p[i] >> a[i] >> n;
            for(int j = 0; j < n; j++) {
                int x, y;
                cin >> x >> y;
                x--;
                d[i][x] *= (100 - y) * 0.01;
            }
        }
        double ans = INF;
        dp[0] = 0.0;
        for(int msk = 0; msk < (1 << m); msk++) {
            double area = 0;
            for(int i = 0; i < m; i++) {
                if((msk >> i) & 1) {
                    area += a[i];
                } else {
                    double cost = p[i];
                    for(int j = 0; j < m; j++) {
                        if((msk >> j) & 1) cost *= d[j][i];
                    }
                    dp[msk | (1 << i)] = min(dp[msk | (1 << i)], dp[msk] + cost);
                }
            }
            if(msk) {
                double tmp = dp[msk] / area;
                ans = min(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}