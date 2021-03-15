#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> s;
        s.insert(0);
        for(int i = 1; i*i <= n; i++) {
            s.insert(n / i);
            s.insert(n / (n / i));
        }
        cout << s.size() << endl;
        for(auto & x: s) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}