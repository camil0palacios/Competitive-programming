#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
    int d; string s;
    cin >> d >> s;
    int n = (int)s.size(), ans = 0;
    bool ok = 0;
    for(int i = 0; i < n * n; i++) {
        int idx = 1, dam = 0, p = 1;
        bool ch = 0;
        for(int j = 0; j < n; j++) {
            if(s[j] == 'C')p <<= 1;
            if(s[j] == 'S')dam += p;
            if(j && s[j-1] == 'C' && s[j] == 'S') {
                idx = j;
                ch = 1;
            }
        }
        if(dam <= d) {
            ok = 1;
            break;
        }
        if(ch) {
            ans++;
            swap(s[idx], s[idx - 1]);
        }
    }
    if(ok)cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}