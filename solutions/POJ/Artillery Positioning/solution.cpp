#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#define endl '\n'
using namespace std;

const int MXN = 110;
const int MXM = 70;
int n, m;
int dp[MXN][MXM][MXM];
int state[MXN];
int pos[MXM], cost[MXM], num_pos;
char a[MXN][MXN];

int legal(int a, int b) { return a & b; }

int go(int i, int pen, int ult) {
    if(i == n) return 0;
    if(dp[i][pen][ult] != -1) return dp[i][pen][ult];
    int ans = 0;
    for(int j = 0; j < num_pos; j++) {
        if(legal(pos[pen], pos[j])) continue; 
        if(legal(pos[ult], pos[j])) continue;
        if(legal(state[i], pos[j])) continue; 
        ans = max(ans, go(i + 1, ult, j) + cost[j]);
    }
    return dp[i][pen][ult] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'H') state[i] |= 1 << j;
        }
    }
    for(int i = 0; i < (1 << m); i++) {
        if(!(i & (i << 1)) && !(i & (i << 2))) {
            int cnt = 0;
            for(int j = i; j; j >>= 1) cnt += j & 1;  
            pos[num_pos] = i;
            cost[num_pos++] = cnt;
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, 0, 0) << endl;
    return 0;
}