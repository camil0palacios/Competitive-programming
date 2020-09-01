#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d, x, y, x1, x2, y1, y2;
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        if(x-a+b < x1 || x-a+b > x2 || y-c+d < y1 || y-c+d > y2)cout << "No" << endl;
        else if(x1 == x2 && a + b != 0)cout << "No" << endl;
        else if(y1 == y2 && c + d != 0)cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}