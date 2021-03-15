#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int bit[32];
        memset(bit, 0, sizeof bit);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            int lst = 0;
            for(int j = 0; j < 32; j++) {
                if((x >> j) & 1) lst = j;
            }
            bit[lst]++;
        }
        ll ans = 0;
        for(int i = 0; i < 32; i++) {
            if(bit[i]) ans += (1LL * bit[i] * (bit[i] - 1) / 2);
        }
        cout << ans << endl;
    }
    return 0; 
}