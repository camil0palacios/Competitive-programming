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
        vector<int> cnt(101);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        int x = 0, y = 0;
        for(x = 0; cnt[x] >= 2; x++);
        for(y = 0; cnt[y] >= 1; y++);
        cout << x + y << endl;
    }
    return 0;
}