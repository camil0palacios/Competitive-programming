#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        if(c) cout << string(c + 1, '1');
        if(a) cout << string(a + 1, '0');
        for(int i = 0; i < (b + 1 - (a != 0) - (c != 0)); i++) cout << ((a != 0) + i) % 2;
        cout << endl; 
    }
    return 0;
}