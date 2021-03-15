#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;

const int MXN = 1e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if(n == 1) cout << -1 << endl;
    else {
        int cnt = count(a, a + n, a[0]);
        vector<int> ans;    
        if(cnt == n) ans.emplace_back(a[0]);
        else {
            map<int,int> m;
            int d = 1e9;
            for(int i = 1; i < n; i++) {
                ++m[a[i] - a[i-1]];
                d = min(d, a[i] - a[i-1]);
            }
            vector<int> f;
            for(auto & p : m) f.emplace_back(p.second);
            if(m.size() == 1) {
                ans.emplace_back(a[0] - d);
                ans.emplace_back(a[n-1] + d);
                if(n == 2 && (a[0] + a[1]) % 2 == 0) ans.emplace_back((a[0] + a[1]) / 2);
            } else if(m.size() == 2 && f[1] == 1) {
                for(int i = 1; i < n; i++) {
                    if(a[i] - a[i-1] != d && a[i-1] + d == a[i] - d) {
                        ans.emplace_back(a[i] - d);
                        break;
                    }
                }
            }
        }
        if(ans.size()) sort(all(ans)); 
        cout << ans.size() << endl;
        for(auto & i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}