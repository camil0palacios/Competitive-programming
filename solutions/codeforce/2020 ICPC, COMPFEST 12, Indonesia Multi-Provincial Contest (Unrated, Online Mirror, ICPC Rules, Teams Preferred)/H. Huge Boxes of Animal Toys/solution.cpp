#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((a + b) % 2 == 0) {
            cout << "Tidak" << " Tidak" << ' ';
            if(c || b) cout << "Ya";
            else cout << "Tidak";
            cout << ' ';
            if(d || a) cout << "Ya";
            else cout << "Tidak";
            cout << endl;
        } else {
            if(a || d) cout << "Ya";
            else cout << "Tidak";
            cout << ' ';
            if(b || c) cout << "Ya";
            else cout << "Tidak";
            cout << ' ';
            cout << "Tidak" << " Tidak" << endl;
        }
    }
    return 0;
}