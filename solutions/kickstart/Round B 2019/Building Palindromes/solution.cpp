#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    int ps[n + 1][27];
    memset(ps, 0, sizeof ps);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 27; j++) {
            ps[i][j] = ps[i - 1][j];
        }
        ps[i][s[i - 1] - 'A']++;
    }
    int ans = 0;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int odd = 0;
        for(int i = 0; i < 27; i++) {
            int x = ps[r][i] - ps[l - 1][i];
            odd += x & 1;
        }
        ans += odd <= 1;
    }
    cout << ans << endl;
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