#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 2002;
int n, k;
int dp[MXN][MXN];
string a[MXN];
string dig[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"}; 
char num[10] = {'0','1','2','3','4','5','6','7','8','9'};
string ans;

int get(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 7; i++) {
        if(a[x][i] == '1' && dig[y][i] == '0') return INF;
        if(a[x][i] == '0' && dig[y][i] == '1') cnt++;
    }
    return cnt;
} 

bool go(int i, int j) {
    if(i == n) return j == k;
    if(dp[i][j] != -1) return dp[i][j];
    for(int l = 9; l >= 0; l--) {
        int cnt = get(i, l);
        if(j + cnt <= k && go(i + 1, j + cnt)) {
            ans[i] = num[l];
            return dp[i][j] = 1;
        }
    }
    return dp[i][j] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    ans = string(n, '0');
    if(go(0, 0)) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}