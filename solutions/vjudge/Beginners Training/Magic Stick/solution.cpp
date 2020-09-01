#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(x == y) cout << "YES" << endl;
        else if(x == 1) cout << "NO" << endl;
        else if((x <= 3 && y <= 3) || (x > 3)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }    
    return 0;
}