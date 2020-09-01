#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int mn = 1000 * 1000 + 5;
        for(int i = 1; i < n; i++) {
            mn = min(mn, abs(a[i] - a[i - 1]));
        }
        cout << mn << endl;
    }
    return 0;
}