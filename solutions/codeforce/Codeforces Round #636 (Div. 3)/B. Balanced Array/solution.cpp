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
        if(n % 4 != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            int a[n];
            int so = 0, se = 0;
            for(int i = 0, inc = 2; i < n/2; i++, inc += 2) {
                a[i] = inc;
                se += inc;
            }
            for(int i = n / 2, inc = 1; i < n - 1; i++, inc += 2) {
                a[i] = inc;
                so += inc;
            }
            a[n - 1] = se - so;
            for(int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}