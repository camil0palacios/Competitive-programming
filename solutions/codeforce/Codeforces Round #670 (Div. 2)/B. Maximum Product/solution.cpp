#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e5 + 5;
ll a[MXN];

int main() {  
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        ll ans = max({
            a[n - 1]*a[n - 2]*a[n - 3]*a[n - 4]*a[n - 5], 
            a[0]*a[1]*a[2]*a[3]*a[n - 1], 
            a[n - 1]*a[n - 2]*a[n - 3]*a[0]*a[1] 
        });
        cout << ans << endl;
    }
    return 0;
}