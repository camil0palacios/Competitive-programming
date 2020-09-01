#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int p[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        for(int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + (s[i - 1] == '0');
        }
        int mn = n;
        for(int i = 1; i <= n; i++) {
            int z1 = p[i], z2 = p[n] - p[i];
            int o1 = abs(i - z1), o2 = abs((n - i) - z2); 
            mn = min(mn, o1 + z2);
            mn = min(mn, z1 + o2);
        }
        cout << mn << endl;
    }
    return 0;
}