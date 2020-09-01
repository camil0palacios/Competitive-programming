#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
char a[55][55];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                cin >> a[i][j];  
            }
        }
        for(int i = 0; i < n; i++) a[n][i] = a[i][n] = '1';
        bool ok = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(a[i][j] == '1') {
                    if(a[i + 1][j] == '1' || a[i][j + 1] == '1') continue;
                    else ok = 0;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl; 
    }
    return 0;
}