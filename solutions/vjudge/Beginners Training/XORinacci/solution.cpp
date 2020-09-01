#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, n;
        cin >> a >> b >> n;
        int ans = 0;
        if(n == 0) ans = a;
        if(n == 1) ans = b;
        else {
            for(int i = 0; i < 30; i++) {
                int x = (a >> i) & 1;
                int y = (b >> i) & 1;
                if(x && !y) {
                    ans |= ((((n - 1) % 3) != 0) << i);
                }
                else if(!x && y) {
                    ans |= ((n % 3 != 0) << i);
                }
                else if(x && y) {
                    ans |= ((((n + 1) % 3) != 0) << i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}