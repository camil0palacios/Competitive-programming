#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        int x = -1, y = -1;
        for(int i = 0; i < n; i++) {
            if((s[i] - '0') & 1) {
                x = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if((s[i] - '0') & 1) {
                y = i;
                break;
            }
        }
        if(x != -1 && y != -1 && x < y) cout << s[x] << s[y] << endl;
        else cout << -1 << endl;
    }
    return 0;
}