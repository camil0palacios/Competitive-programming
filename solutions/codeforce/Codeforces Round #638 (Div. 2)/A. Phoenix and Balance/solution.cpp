#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 2) cout << 2 << endl;
        else {
            int a = (1 << n), b = 0;
            for(int i = 1; i < n/2; i++) {
                a += (1 << i);
            }
            for(int i = n/2; i < n; i++) {
                b += (1 << i);
            }
            cout << abs(a - b) << endl;
        }
    }
    return 0;
}