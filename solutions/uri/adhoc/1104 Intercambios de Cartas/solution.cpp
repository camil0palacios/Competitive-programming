#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int no_reply(unordered_map<int,int>& a, vector<bool>& block, int mx) {
    int ans = 0;
    vector<bool> can(mx + 1);
    for(auto & p : a) {
        int x = p.first;
        if(!block[x] && !can[x]) {
            can[x] = 1;
            ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m, n && m) {
        unordered_map<int, int> a, b;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            a[x]++;
            mx = max(mx, x);
        }
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            b[x]++;
            mx = max(mx, x);
        }
        vector<bool> block(mx + 1);
        for(auto & p : a) {
            int x = p.first;
            if(b.count(x)) {
                block[x] = 1;
            }
        }
        int ans = min(no_reply(a, block, mx), no_reply(b, block, mx));
        cout << ans << endl;
    }
    return 0;
}