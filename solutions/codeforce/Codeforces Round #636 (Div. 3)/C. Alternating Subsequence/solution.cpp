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
        long long sum = 0, lst = 0, mx = -1e9;
        for(int i = 0; i < n; i++) {
            long long x; cin >> x;
            if(lst == 0 || lst * x > 0) {
                mx = max(mx, x);
            } else {
                sum += mx;
                mx = x;
            }
            lst = x;
        }
        sum += mx;
        cout << sum << endl;
    }
    return 0;
}