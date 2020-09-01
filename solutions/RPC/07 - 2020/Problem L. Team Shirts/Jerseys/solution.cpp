#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 25;
string s, a[MXN];
int n;
bitset<(1 << (MXN + 2))> dp;
bitset<(1 << (MXN + 2))> vis;

bool match(int idx, int i) {
    // if(idx + a[i].size() > s.size()) return 0;
    // for(int j = 0; j < a[i].size(); j++) {
    //     if(a[i][j] != s[idx + j]) return 0;
    // }
    // return 1;
    return idx + a[i].size() <= s.size() && s.substr(idx, a[i].size()) == a[i];
}

bool Dp(int idx, int msk) {
    if(idx == s.size()) return 1;
    if(vis[msk] == 1) return dp[msk];
    vis[msk] = 1;
    if((msk >> n) == 0 && s[idx] != '0') {
        bool ans = Dp(idx + 1, msk | (1 << n));
        if(!ans && idx + 2 <= s.size()) ans = Dp(idx + 2, msk | (1 << (n + 1)));
        if(ans) return dp[msk] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(!((msk >> i) & 1)) {
            if(match(idx, i)) {
                bool ans = Dp(idx + a[i].size(), msk | (1 << i)); 
                if(ans) return dp[msk] = 1;
            }
        }
    }
    return dp[msk] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < (1 << (n + 2)); i++) {
        vis[i] = 0;
    }
    cout << Dp(0, 0) << endl;
    return 0;
}