#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        a += s[i] == 'A';
        b += s[i] == 'B';
    }
    cout << (abs(a - b) == 1 ? 'Y' : 'N') << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}