#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll INF = 1e18;

ll cal(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll ans = (x1 + x2 + x3) * max(y1, max(y2, y3));
    if(y1 >= y2) {
        ans = min(ans, max(x1 + x2, x3) * (y1 + y3));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int m[3][2];
        for(int i = 0; i < 3; i++) cin >> m[i][0] >> m[i][1]; 
        ll ans = INF;
        int p[3] = {0, 1, 2};
        do {
            for(int i = 0; i < (1 << 3); i++) {
                int x[3], y[3];
                for(int i = 0; i < 3; i++) {
                    x[i] = m[p[i]][0];
                    y[i] = m[p[i]][1];
                }
                if(i & 1) swap(x[0], y[0]);
                if(i & 2) swap(x[1], y[1]);
                if(i & 4) swap(x[2], y[2]);
                ans = min(ans, cal(x[0], y[0], x[1], y[1], x[2], y[2]));
            }
        } while(next_permutation(p, p + 3));
        cout << ans << endl;
    }
    return 0;
}