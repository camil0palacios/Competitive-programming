#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 110;
int a[MXN], b[MXN];

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
        for(int i = 1; i < n; i += 2) {
            cout << -a[i] << ' ' << a[i - 1] << ' ';
        }
        cout << endl;
    }
    return 0;
}