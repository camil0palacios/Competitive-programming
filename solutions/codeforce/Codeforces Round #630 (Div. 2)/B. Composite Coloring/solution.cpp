#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[1000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int col[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            col[i] = 0;
        }
        int p[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int w = 1;
        for(int i = 0; i < 11; i++) {
            bool ok = 0;
            for(int j = 0; j < n; j++) {
                if(!col[j] && a[j] % p[i] == 0) {
                    ok = 1;
                    col[j] = w;
                }
            }
            w += ok;
        }
        cout << w - 1 << endl;
        for(int i = 0; i < n; i++) {
            cout << col[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}