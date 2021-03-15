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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool equal = 1;
        int x = a[0];
        for(int i = 0; i < n; i++) {
            if(x != a[i]) equal = 0;
        }
        if(equal) cout << -1 << endl;
        else {
            int mx = 0, ans = 0;
            for(int i = 0; i < n; i++) {
                mx = max(mx, a[i]);
            }
            for(int i = 0; i < n; i++){ 
                if(i && a[i] == mx && a[i] > a[i - 1]) ans = i + 1;
                if(i + 1 < n && a[i] == mx && a[i] > a[i + 1]) ans = i + 1;
            }
            cout << ans << endl;
        }
    }
    return 0; 
}