#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

// 4 2 1 3 5
// 1 3 4 2 0
// 3 1 0 2 4
// 1 3 4 2 0
// 3 1 0 2 0
//  so on....  

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll mx = *max_element(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            a[i] = mx - a[i];
        }
        if(k % 2 == 0) {
            ll mx = *max_element(a.begin(), a.end());
            for(int i = 0; i < n; i++) {
                a[i] = mx - a[i];
            }
        }
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}