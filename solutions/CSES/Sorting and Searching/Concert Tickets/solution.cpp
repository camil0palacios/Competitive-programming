#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for(int i = 0; i < n; i++) {
        int hi;
        cin >> hi;
        h.insert(-hi);
    }
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto it = h.lower_bound(-t);
        if(it != h.end()) {
            cout << -(*it) << endl;
            h.erase(it);
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}