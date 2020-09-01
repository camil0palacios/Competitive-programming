#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int a[2*MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < (n << 1); i++) {
            cin >> a[i];
        }
        sort(a, a + (n << 1));
        cout << a[n] - a[n - 1] << endl;
    }
    return 0;
}