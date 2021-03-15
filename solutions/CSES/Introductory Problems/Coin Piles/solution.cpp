#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b) ? "YES" : "NO") << endl;
    }
    return 0;
}