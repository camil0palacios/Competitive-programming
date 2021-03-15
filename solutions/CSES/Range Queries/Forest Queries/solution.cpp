#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1010;
int n, q;
int bit[MXN][MXN];

void update(int x, int y, int val) {
    for(; x <= n; x += x & -x) {
        for(; y <= n; y += y & -y) {
            bit[x][y] += val;
        }
    }
}

int query(int x, int y) {
    int ans = 0;
    for(; x; x -= x & -x) {
        for(; y; y -= y & -y) {
            ans += bit[x][y];
        }
    }
    return ans;
}

int dp[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (c == '*'); 
            // if(c == '*') update(i, j, 1);
        }
    }
    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]; 
        // int ans =  query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
        cout << ans << endl;
    }
    return 0;
}