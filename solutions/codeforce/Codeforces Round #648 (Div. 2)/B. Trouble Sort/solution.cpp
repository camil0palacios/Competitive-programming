#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[505], b[505];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int z = 0, o = 0, s = 1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i && a[i - 1] > a[i]) s = 0;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            z |= b[i] == 0;
            o |= b[i] == 1;
        }
        cout << ((z && o) || s ? "Yes" : "No") << endl;
    }
    return 0;
}