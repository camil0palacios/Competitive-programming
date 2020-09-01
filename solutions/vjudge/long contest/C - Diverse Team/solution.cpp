#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        m[x] = i;
    }
    if(m.size() >= k) {
        cout << "YES" << endl;
        int i = 0;
        for(auto & e : m) {
            if(i == k) break;
            cout << e.second + 1 << ' ';
            i++;
        }
        cout << endl;
    }
    else cout << "NO" << endl;
    return 0;
}