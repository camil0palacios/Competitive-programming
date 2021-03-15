#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 110;
int a[MXN][MXN];

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
                if((i + j) % 2) a[i][j] += a[i][j] % 2 == 0 ? 1 : 0;
                else a[i][j] += a[i][j] % 2 != 0 ? 1 : 0;
                cout << a[i][j] << ' '; 
            }
            cout << endl;
        }
    }
    return 0;
}