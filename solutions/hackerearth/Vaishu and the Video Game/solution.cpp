#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXL = 55;
const int MXN = 22;
const int INF = 1e9;
int L, N, M;
int a[MXL];
int dp[1 << MXN];

int Dp(int msk) {
    if(dp[msk] != -1)return dp[msk];
    int ans = INF;
    bool ok = 0;
    for(int i = 0; i < L; i++) {
        int x = a[i] | msk; 
        int cnt = 0;
        for(int j = 0; j < 21; j++) {
            cnt += ((x >> j) & 1) != ((msk >> j) & 1);
        }
        if(cnt){
            ans = min(ans, Dp(x) + (int)pow(cnt, M));
            ok = 1;
        }
    }
    if(!ok)ans = 0;
    return dp[msk] = ans;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> L >> N >> M;
    for(int i = 0; i < L; i++) {
        int h; cin >> h;
        int msk = 0;
        for(int j = 0; j < h; j++) {
            int x; cin >> x;
            msk |= (1 << x);
        }
        a[i] = msk;
    }
    memset(dp, -1, sizeof dp);
    int ans = Dp(0);
    cout << ans << endl;
    return 0;
}