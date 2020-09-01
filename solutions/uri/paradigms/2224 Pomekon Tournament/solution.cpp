#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const double INF = 1e9;
const int MXN = 16;
int n;
double x[MXN], y[MXN];
double dp[1 << 16];
bool vis[1 << 16];

double dist(int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j]; 
    return sqrt(dx*dx + dy*dy);
}

double Dp(int msk) {
    if(msk == (1 << n) - 1) return 0;
    if(vis[msk]) return dp[msk];
    double ans = INF;
    for(int i = 0; i < n; i++) {
        if(!((msk >> i) & 1)) {
            for(int j = i + 1; j < n; j++) {
                if(!((msk >> j) & 1))
                    ans = min(ans, Dp(msk | (1 << i) | (1 << j)) + dist(i, j));
            }
            break;
        }
    }
    vis[msk] = 1;
    return dp[msk] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        for(int i = 0; i < (1 << n); i++) vis[i] = 0; 
        cout << Dp(0) << endl;
    }
    return 0;
}