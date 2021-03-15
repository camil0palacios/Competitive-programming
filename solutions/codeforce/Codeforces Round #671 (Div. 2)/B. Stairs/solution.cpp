#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        int ans = 0;
        ll p = 1, sum = 0;
        while(true) {
            sum += p;
            if(x < sum * (sum + 1) / 2) break;
            else  x -= sum * (sum + 1) / 2;
            p *= 2, ans++;
        }
        cout << ans << endl;
    }
    return 0;
}