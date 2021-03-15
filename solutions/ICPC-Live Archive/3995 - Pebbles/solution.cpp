#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
int a[15][15];
int dp[17][17][1 << 15];

int go(int i, int j, int msk) {
    if(i == n) return 0;
    if(dp[i][j][msk] != -1) return dp[i][j][msk];
    int ans = 0;
    if(j >= n) ans = go(i + 1, 0, msk);
    else {
        int nmsk = msk;
        if((nmsk >> j) & 1) nmsk &= ~(1 << j);
        ans = go(i, j + 1, nmsk);
        if(!((msk >> j) & 1)) {
            nmsk = msk | (1 << j);
            if(j - 1 >= 0) nmsk |= (1 << (j - 1));
            if(j + 1 < n) nmsk |= (1 << (j + 1));
            ans = max(ans, go(i, j + 2, nmsk) + a[i][j]);
        }
    }
    return dp[i][j][msk] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(getline(cin, s)) {
        n = 0;
        stringstream ss(s);
        while(ss >> a[0][n]) n++;
        if(n == 0) break;
        for(int i = 1; i < n; i++) {
            getline(cin, s);
            stringstream ss(s);
            int j = 0;
            while(ss >> a[i][j]) j++;
        }
        getline(cin, s);
        memset(dp, -1, sizeof dp);
        cout << go(0, 0, 0) << endl;
    }
    return 0;
}