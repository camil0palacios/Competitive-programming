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
        int ans = 0;
        if(n % 2 == 0) {
            ans = 1;
            for(int i = 0; i < s.size(); i++) {
                if((s[i] - '0') % 2 == 0 && (i & 1)) ans = 2;
            }
        } else {
            ans = 2;
            for(int i = 0; i < s.size(); i++) {
                if((s[i] - '0') % 2 != 0 && i % 2 == 0) ans = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}