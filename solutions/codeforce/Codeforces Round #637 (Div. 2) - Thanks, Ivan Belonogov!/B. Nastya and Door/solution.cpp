#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN], b[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 2; i <= n - 1; i++) {
            b[i] = b[i - 1] + (a[i - 1] < a[i] && a[i] > a[i + 1]);
        }
        int l = 0, mx = -1;
        for(int i = 1, j = k; j <= n; i++, j++) {
            int x = b[j - 1] - b[i];
            if(mx < x) {
                mx = x; l = i;
            }
        }
        cout << mx + 1 << ' ' << l << endl;
    }
    return 0;
}