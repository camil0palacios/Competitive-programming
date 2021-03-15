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
        for(int i = 4*n, j = 0; i >= 0 && j < n; i -= 2, j++) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}