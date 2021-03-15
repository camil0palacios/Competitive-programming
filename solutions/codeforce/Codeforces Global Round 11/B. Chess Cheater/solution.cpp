#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ans = 2*min(n, count(s.begin(), s.end(), 'W') + k);
        vector<int> gap;
        int l = n;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'W') {
                if(l < i) gap.emplace_back(i - l);
                l = i + 1;
            }
        }
        if(ans) ans -= gap.size() + 1;
        sort(gap.begin(), gap.end());
        for(auto & i : gap) {
            if(k < i) break;
            k -= i;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}