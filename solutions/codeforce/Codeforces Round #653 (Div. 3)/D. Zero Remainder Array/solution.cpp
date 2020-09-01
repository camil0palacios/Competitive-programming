#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        map<int,int> cnt;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x % k == 0) continue;
            cnt[k - x % k]++;
        }
        long long ans = 0;
        for(auto & p : cnt) {
            ans = max(ans, 1LL*(p.second - 1) * k + 1LL*p.first + 1);
        }
        cout << ans << endl;
    }
    return 0;
}