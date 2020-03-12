#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1005;
int f[2][MAXN], p[2][MAXN];

int Dp(int n) {
    int cur_dp1 = 0, prv_dp1 = 0;
    int cur_dp2 = 0, prv_dp2 = 0;
    for(int i = n - 1; i >= 0; i--) {
        cur_dp1 = prv_dp1 + f[0][i];
        cur_dp2 = prv_dp2 + f[1][i];
        if(i < n - 1) {
            cur_dp1 = min(cur_dp1, prv_dp2 + f[0][i] + p[0][i]);
            cur_dp2 = min(cur_dp2, prv_dp1 + f[1][i] + p[1][i]);
        }
        prv_dp1 = cur_dp1;
        prv_dp2 = cur_dp2;
    }
    return min(cur_dp1, cur_dp2);
}

void sol() {
    int n;
    cin >> n;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> f[i][j];
        }
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n - 1; j++) {
            cin >> p[i][j];
        }
    }
    cout << Dp(n) << endl;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol();
    }
    return 0;
}