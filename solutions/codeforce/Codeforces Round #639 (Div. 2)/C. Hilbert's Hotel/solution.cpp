#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        set<int> s;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            s.insert((i + (a % n) + n) % n);
        }
        cout << (s.size() == n ? "YES" : "NO") << endl;
    }
    return 0;
}