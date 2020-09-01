#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int l = 0, r = -1, ans = 1e9, x = 0, y = 0;
        map< pair<int, int>, int > p;
        p[{0, 0}] = 0;
        for(int i = 1; i <= n; i++) {
            x += s[i-1] == 'R';
            x -= s[i-1] == 'L';
            y += s[i-1] == 'U';
            y -= s[i-1] == 'D';
            if(p.count({x, y}) && (i - p[{x, y}] + 1) < ans) {
                l = p[{x, y}], r = i - 1;
                ans = r - l + 1;
            }
            p[{x, y}] = i;
        }
        if(r != -1) cout << l + 1 << ' ' << r + 1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}