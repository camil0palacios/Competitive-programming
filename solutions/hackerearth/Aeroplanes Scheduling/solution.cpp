#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 5005;
int n;
int a[MXN], b[MXN], mni[MXN];
int dp[MXN][MXN];

int go(int i, int mn) {
    if(i == n + 1) return 0;
    if(dp[i][mn] != -1) return dp[i][mn];
    int ans = 0;
    int mn1 = mni[i - 1];
    int mn2 = mn;
    if(a[i] > mn1 && a[i] > mn2) {
        ans = go(i + 1, mn);
    }
    if(a[i] <= mn1) {
        ans = max(ans, go(i + 1, mn1) + 1);
        ans = max(ans, go(i + 1, mn2) + 1);
    }
    if(a[i] <= mn2 && a[i] > mn1) {
        ans = max(ans, go(i + 1, a[i]) + 1);
        ans = max(ans, go(i + 1, mn2));
    }
    return dp[i][mn] = ans;
}

int compress() {
    map<int, int> m;
    sort(b + 1, b + n + 1);
    int x = 0;
    for(int i = 1; i <= n; i++) {
        if(!m.count(b[i]))m[b[i]] = x++;
    }
    for(int i = 1; i <= n; i++) {
        a[i] = m[a[i]];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    compress();
    mni[0] = MXN;
    for(int i = 1; i <= n; i++) {
        mni[i] = min(a[i], mni[i - 1]);
    }
    memset(dp, -1, sizeof dp);
    cout << go(1, MXN - 1) << endl;
    return 0;
}