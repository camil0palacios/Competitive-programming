#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long ans = 0;
        long long x = n / 2;
        for(int i = 1; i <= x; i++) {
            ans += (long long)8*i*i;
        }
        cout << ans << endl;
    }
    return 0;
}