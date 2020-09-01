#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[50];

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
        int m = 0, e = 0, o = 0;
        for(int i = 0; i < n; i++) {
            m += a[i] % 2 != i % 2;
            e += a[i] % 2 == 0;
            o += a[i] % 2 != 0;
        }
        if(e == (n + 1) / 2 && o == n - ((n + 1) / 2)) {
            cout << m / 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}