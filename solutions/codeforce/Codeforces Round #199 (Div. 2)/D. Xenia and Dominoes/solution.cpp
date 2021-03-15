#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1000000007;
const int MXN = 1e4 + 5;
int n;
char a[3][MXN];
int nxt[MXN];
int row, col;
ll dp[MXN][1 << 3][2];

bool can(int a, int b) { 
    int i = 0;
    while(i < 3) {
        int bita = (a >> i) & 1, bitb = (b >> i) & 1;
        if(bita && bitb) return 0;
        if(bita == bitb) {
            if(i + 1 < 3) {
                bita = (a >> (i + 1)) & 1, bitb = (b >> (i + 1)) & 1;
                if(bita == 0 && bita == bitb) i += 2;
                else return 0;
            } 
            else return 0;
        } else i++;
    }
    return 1;
}

bool check(int idx, int msk, int nmsk) {
    if(idx == col) {
        if(row == 0) return msk == 1 && nmsk == 0;
        if(row == 2) return msk == 4 && nmsk == 0;
    }
    if(idx + 2 < n && idx + 2 == col) return (nmsk >> row) & 1;
    if(idx - 1 >= 0 && idx - 1 == col) return (nmsk >> row) & 1;
    return 0;
}

bool legal(int a, int b) { return a & b; }

ll go(int idx, int msk, bool flag) {
    if(idx == n) return msk == 0 && flag;
    if(dp[idx][msk][flag] != -1) return dp[idx][msk][flag];
    ll ans = 0;
    for(int nmsk = 0; nmsk < (1 << 3); nmsk++) {
        if(can(msk, nmsk) && !legal(nmsk, nxt[idx + 1])) {
            ans += go(idx + 1, nmsk | nxt[idx + 1], flag || check(idx, msk, nmsk));
            ans %= mod;
        }
    }
    return dp[idx][msk][flag] = ans;
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'O') row = i, col = j;
        }
    }
    for(int j = 0; j < n; j++) {
        int msk = 0;
        for(int i = 0; i < 3; i++) {
            if(a[i][j] == 'X' || a[i][j] == 'O') msk |= 1 << i;
        }
        nxt[j] = msk;
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, nxt[0], 0) << endl;
    return 0;
}