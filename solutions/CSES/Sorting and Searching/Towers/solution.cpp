#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        auto it = s.upper_bound(x);
        if(it != s.end()) {
            s.erase(it);
        }
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}