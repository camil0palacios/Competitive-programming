#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int mov = -1, x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if((s[i] == 'L' || s[i] == 'R') && mov != 1) {
                x += s[i] == 'R' ? 1 : -1;
                mov = 1;
            }
            if((s[i] == 'U' || s[i] == 'D') && mov != 2) {
                y += s[i] == 'U' ? 1 : -1;
                mov = 2; 
            }
        }
        cout << x << ' ' << y << endl;
    }
    return 0;
}