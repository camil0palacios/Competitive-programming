#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; string s; 
        cin >> n >> s;
        bool ok = 1;
        for(int i = 0; i < n / 2; i++) {
            int x = abs(s[i] - s[n - i - 1]);
            if(x > 2 || x == 1)
                ok = 0; 
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}