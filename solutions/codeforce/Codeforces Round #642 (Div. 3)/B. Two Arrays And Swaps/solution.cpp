#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[31], b[31];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int s = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i]; s += a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        for(int i = 0; i < n && k; i++) {
            if(a[i] < b[n - i - 1]) {
                s -= a[i];
                s += b[n - i - 1];
                k--;
            }
        }
        cout << s << endl;
    }
    return 0;
}