#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long a, b;
        cin >> a >> b;
        long long ans = 0;
        if(a <= b) {
            ans = b - a;
        } else {
            ans = (b * (a / b) + (a % b != 0 ? b : 0)) - a;
        }
        cout << ans << endl;
    }
    return 0;
}