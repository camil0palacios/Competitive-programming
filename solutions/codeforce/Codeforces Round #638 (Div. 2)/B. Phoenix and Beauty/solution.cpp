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
        set<int> s;
        for(int i = 1; i <= n; i++) {
            int a; cin >> a;
            s.insert(a);
        }
        if(s.size() > k) {
            cout << -1 << endl;
        } else {
            cout << n * k << endl;
            for(int i = 0; i < n; i++) {
                for(auto & j : s) {
                    cout << j << ' ';
                }
                for(int j = 0; j < k - s.size(); j++) {
                    cout << 1 << ' ';
                }
            }
            cout << endl;
        }
    }
    return 0;
}