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
        int ev = 0, od1 = 0, od2 = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(!ev && x % 2 == 0) ev = i + 1;
            else if(!od1 && x & 1) od1 = i + 1;
            else if(!od2 && x & 1) od2 = i + 1;
        }
        if(ev) {
            cout << 1 << endl << ev << endl;
        }
        else if(od1 && od2) {
            cout << 2 << endl;
            cout << od1 << ' ' << od2 << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}