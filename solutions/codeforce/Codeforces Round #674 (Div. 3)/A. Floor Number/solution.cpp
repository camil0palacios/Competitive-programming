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
        int apt = 1, flr = 1;
        if(n <= 2) cout << flr << endl;
        else {
            apt = 3, flr = 2;
            while(true) {
                if(apt <= n && n <= apt + x - 1) break;
                apt += x;
                flr++;
            } 
            cout << flr << endl;
        }
    }
    return 0;
}