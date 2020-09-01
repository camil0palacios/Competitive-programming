#include <bits/stdc++.h>
#define endl '\n'
#define sz(v) (int) v.size()
using namespace std;

const int MXN = 100;
string a, b, v, res;
int dp[MXN][MXN][MXN];
int fail[MXN];

void kmp(string & s) {
    int j = 0;
    for(int i = 1; i < sz(s); i++) {
        while(j && s[i] != s[j]) j = fail[j - 1];
        if(s[i] == s[j]) j++;
        fail[i] = j;
    }
}

int get(char c, int j) {
    while(j && c != v[j]){
        j = fail[j - 1];
    }
    return j + (c == v[j]);
}

int Dp(int i, int j, int k) {
    if(k == sz(v)) return -1000;
    if(i == sz(a) || j == sz(b)) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ans = max(Dp(i + 1, j, k), Dp(i, j + 1, k));
    if(a[i] == b[j]) {
        int nk = get(a[i], k);
        ans = max(ans, Dp(i + 1, j + 1, nk) + 1);
    } 
    return dp[i][j][k] = ans;
}

void print(int i,int j,int k){
    if(k==sz(v)) return;
    if(i == a.size() || j == b.size()) return;
    int val = Dp(i, j, k);
    if(val == Dp(i + 1, j, k)){
        return print(i + 1, j, k);
    }
    if(val == Dp(i, j + 1, k)){
        return print(i, j + 1, k);
    }
    if(a[i] == b[j]){
        int nk = get(a[i], k);
        if(val == Dp(i + 1, j + 1, nk) + 1) {
            res += a[i];
            return print(i + 1, j + 1, nk);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b >> v;
    kmp(v);
    memset(dp, -1, sizeof dp);
    int ans = Dp(0, 0, 0);
    if(ans > 0) {
        print(0, 0, 0);
        cout << res;
    } else {
        cout << 0;
    }
    return 0;
}