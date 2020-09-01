#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        bool ok = n >= d;
        for(long long i = 1; i * i <= d && i <= n; i++) {
            if(i + (d + i) / (i + 1) <= n) ok = 1;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}