#include <bits/stdc++.h>
#define endl '\n'
#define all(v)  v.begin(), v.end()
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef pair<int, int> ii;

const int MXN = 1e5 + 5;
const int mod = 100000000;
int n;
vector<ii> a;
int dp[MXN];

int bs(int idx) {
    int l = -1, r = n - 1;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if(a[idx].ss <= a[mid].ff) r = mid;
        else l = mid;
    }
    if(a[idx].ss <= a[r].ff && idx != r) return r;
    return -1;
}

int Dp(int idx) {
    if(idx == n) return 0;
    if(dp[idx] != -1) return dp[idx];
    int ans = (1 + Dp(idx + 1)) % mod;
    int nxt = bs(idx);
    if(nxt != -1) ans = (ans + Dp(nxt)) % mod;
    return dp[idx] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n && n != -1) {
        a.assign(n, ii());
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(all(a));
        memset(dp, -1, sizeof dp);
        int res = Dp(0);
        int ans[8]; 
        memset(ans, 0, sizeof ans);
        int x = 7;
        while(res) {
            ans[x--] = res % 10;
            res /= 10;
        }
        for(int i = 0; i < 8; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;   
}