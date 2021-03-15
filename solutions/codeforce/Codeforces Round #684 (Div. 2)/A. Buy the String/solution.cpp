#include <bits/stdc++.h>
#define endl '\n'
#define fori(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, c0, c1, h;
        string s;
        cin >> n >> c0 >> c1 >> h >> s;
        int o = 0, z = 0;
        fori(i, 0, n) {
            z += s[i] == '0';
            o += s[i] == '1';
        }
        int ans = c0*z + c1*o;
        ans = min(ans, min(c0*(z + o) + h*o, c1*(z + o) + h*z));
        cout << ans << endl;
    }
    return 0;
}