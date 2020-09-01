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
        vector<int> f;
        for(int i = 2; i * i <= n && f.size() < 2; i++) {
            if(n % i == 0) {
                f.push_back(i);
                n /= i;
            }
        }
        if(n > 1 && f.size() == 2 && f[0] != n && f[1] != n) {
            cout << "YES" << endl;
            cout << f[0] << ' ' << f[1] << ' ' << n << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}