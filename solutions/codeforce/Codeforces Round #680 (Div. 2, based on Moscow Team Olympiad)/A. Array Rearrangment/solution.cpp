#include <bits/stdc++.h>
#define endl '\n'
#define fori(i, a, b) for(int i = a; i < b; i++)
using namespace std;

const int MXN = 1010;
int a[MXN], b[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        fori(i, 0, n) cin >> a[i];
        fori(i, 0, n) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        bool ok = 1;
        fori(i, 0, n) {
            if(a[i] + b[i] > x) ok = 0;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}