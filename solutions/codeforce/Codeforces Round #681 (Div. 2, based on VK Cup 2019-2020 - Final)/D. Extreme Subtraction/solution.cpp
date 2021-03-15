#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 30050;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i  = 1; i < n; i++) {
            a[0] -= max(0, a[i - 1] - a[i]);
        }
        cout << (a[0] >= 0 ? "YES" : "NO") << endl;
    }
    return 0;
}