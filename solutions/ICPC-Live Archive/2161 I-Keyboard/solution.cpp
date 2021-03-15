#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll INF = 1e18;
const int MXK = 95;
int k, l;
ll f[MXK];
ll dp[MXK][MXK];
string keys, letters;

ll go(int i, int st) {
    if(i == k) return st == l ? 0 : INF;
    if(dp[i][st] != -1) return dp[i][st];
    ll ans = INF, sum = 0;
    for(int j = st; j < l; j++) {
        sum += (j - st + 1) * f[j];
        ans = min(ans, go(i + 1, j + 1) + sum);
    }
    return dp[i][st] = ans;
}

void rec(int i, int st, vector<string>& ans) {
    if(i == k) return;
    int nxt = 0; ll sum = 0;
    for(int j = st; j < l; j++) {
        sum += (j - st + 1) * f[j];
        if(go(i, st) == go(i + 1, j + 1) + sum) {
            ans[i] = letters.substr(st, j - st + 1);
            rec(i + 1, j + 1, ans);
            return;
        }
    }
}

void solve() {
    cin >> k >> l;
    cin >> keys >> letters; 
    for(int i = 0; i < l; i++) {
        cin >> f[i];
    }
    memset(dp, -1, sizeof dp);
    go(0, 0);
    vector<string> ans(k);
    rec(0, 0, ans);
    for(int i = 0; i < k; i++) {
        cout << keys[i] << ": " << ans[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Keypad #" << cs << ":" << endl;
        solve();
    }
    return 0;
}