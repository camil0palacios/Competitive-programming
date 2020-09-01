#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[20000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int odd = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            odd += a[i] & 1;
        }
        if((odd == n && n & 1) || (odd && odd < n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}