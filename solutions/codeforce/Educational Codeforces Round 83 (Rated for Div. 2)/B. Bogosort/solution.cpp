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
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        reverse(a, a + n);
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}