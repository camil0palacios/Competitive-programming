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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int l = 0, r = n - 1;
        for(; a[l] != 1; l++) {}
        for(; a[r] != 1; r--) {}
        int ans = 0;
        for(int i = l; i <= r; i++) {
            ans += a[i] == 0;
        }
        cout << ans << endl;
    }
    return 0;
}