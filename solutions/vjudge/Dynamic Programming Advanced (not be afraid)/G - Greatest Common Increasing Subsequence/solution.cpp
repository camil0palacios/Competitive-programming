// #include <bits/stdc++.h>
#include <iostream>
#define endl '\n'
using namespace std;

const int MXN = 500;
int n, m, a[MXN], b[MXN];
int dp[MXN][MXN];
map<int, int> nxt[MXN];

int Dp(int i, int j) {
    if(i == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    for(int k = i; k < n; k++) {
        if(a[i] < a[k]){
            int pj = nxt[j][a[k]];
            if(pj != -1)
                ans = max(ans, Dp(i + 1, pj) + 1);
        }
    }
    return dp[i][j] = ans;
}

void calc() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool ok = 0;
            for(int k = j + 1; k < m; k++) {
                if(a[i] == a[k]){
                    nxt[j][a[i]] = k; 
                    ok = 1;
                    break;
                }
            }
            if(!ok) nxt[j][a[i]] = -1;
        }
    }
}

void rec(int i, int j) {
    if(i == n) {
        cout << endl;
        return;
    }
    for(int k = i + 1; i < m; k++) {
        if(a[i] == b[k] && st == dp[i + 1][k + 1] + 1) {
            cout << a[i] << ' ';
            rec(i + 1, k + 1);
            return;
        }
    }
}

void clearDp() {
    for(int i = 0; i < MXN; i++) {
        for(int j = 0; j < MXN; j++) {
            dp[i][j] = -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    clearDp();
    calc();
    cout << Dp(0, 0) << endl;
    rec(0, 0);
    return 0;
}