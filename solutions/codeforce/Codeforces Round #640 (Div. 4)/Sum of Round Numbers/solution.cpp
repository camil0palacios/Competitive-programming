#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int p = 1;
        vector<int> ans;
        while(n) {
            int tmp = n % 10;
            if(tmp) ans.emplace_back(tmp * p);
            n /= 10;
            p *= 10;
        }
        cout << ans.size() << endl;
        for(auto & res : ans) {
            cout << res << ' ';
        }
        cout << endl;
    }
    return 0;
}