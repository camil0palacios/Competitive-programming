#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 35;
int path[2][MXN*MXN];
bool a[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        memset(path, 0, sizeof path);
        int sz = n + m - 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                path[a[i][j]][i + j]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < sz / 2; i++) {
            ans += min(path[0][i] + path[0][sz - i - 1], path[1][i] + path[1][sz - i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}