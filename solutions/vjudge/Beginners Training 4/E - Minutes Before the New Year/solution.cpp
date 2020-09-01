#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int h, m;
        cin >> h >> m;
        int ans = (60 - m) + (24 - (h + 1)) * 60;
        cout << ans << endl;
    }
    return 0;
}