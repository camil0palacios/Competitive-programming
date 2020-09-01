#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[55][55];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        bool row[n], col[m];
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                if(a[i][j]) row[i] = col[j] = 1;
            }
        }
        bool turn = 0, ok = 1;
        while(ok) {
            ok = 0;
            for(int i = 0; i < n && !ok; i++) {
                for(int j = 0; j < m && !ok; j++) {
                    if(!row[i] && !col[j]) {
                        row[i] = col[j] = ok = 1;
                    } 
                }
            }
            turn ^= 1;
        }
        cout << (turn ? "Vivek" : "Ashish") << endl;
    }
    return 0;
}