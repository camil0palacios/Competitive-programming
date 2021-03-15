#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        int ans = 0;
        for(int j = 1; j * j <= x; j++) {
            if(x % j == 0) {
                ans++;
                if(x / j != j) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}