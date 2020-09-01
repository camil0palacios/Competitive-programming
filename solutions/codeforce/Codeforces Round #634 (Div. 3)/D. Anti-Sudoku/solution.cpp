#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s[9];
        for(int i = 0; i < 9; i++) {
            cin >> s[i];
        }
        int desj = 0;
        for(int i = 0; i < 9; i += 3) {
            int desi = 0;
            for(int j = 0; j < 9; j += 3) {
                for(int k = 1; k <= 9; k++) {
                    if(s[i + desi][j + desj] != char(k + '0')) {
                        s[i + desi][j + desj] = char(k + '0');
                        break;
                    }
                }
                desi++;
            }
            desj++;
        }
        for(int i = 0; i < 9; i++) {
            cout << s[i] << endl;
        }
    }
    return 0;
}