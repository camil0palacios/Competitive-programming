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
        int od = 0, ev = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            od += x & 1;
            ev += !(x & 1);
        }
        if( (od & 1) || (od && ev) ) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}