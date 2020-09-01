#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int mx = b[0];
    a[0] = b[0];
    for(int i = 1; i < n; i++) {
        a[i] = b[i] + mx;
        mx = max(mx, a[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}