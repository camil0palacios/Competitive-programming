#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool check(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, z;    
        if(check(a, b, c)) {
            x = a, y = b, z = c;
        }
        else if(check(a, b, d)) {
            x = a, y = b, z = d;
        }
        else if(check(b, b, c)) {
            x = b, y = b, z = c;
        }
        else if(check(b, c, c)) {
            x = b, y = c, z = c;
        }
        else if(check(b, c, d)) {
            x = b, y = c, z = d;
        }
        cout << x << ' ' << y << ' ' << z << endl;
    }
    return 0;
}