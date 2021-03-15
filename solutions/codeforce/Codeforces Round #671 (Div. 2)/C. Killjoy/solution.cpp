#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(auto & i : a) cin >> i;
        sort(a.begin(), a.end());
        if(a[0] == x && a[n - 1] == x) cout << 0 << endl;
        else {
            int up = 0, down = 0, ok = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] == x) { ok = 1; continue; }
                if(a[i] < x) up += x - a[i];
                else down += a[i] - x;
            }
            if(up - down == 0 || ok) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
    return 0;
}