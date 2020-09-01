#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int z = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            sum += x;
            z += x == 0;
        }
        int ans = z;
        if(sum + z == 0)ans++;
        cout << ans << endl;
    }    
    return 0;
}