#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const double PI = acos(-1);
const double EPS = 0.0000001;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, w, h, a;
    double x, y;    
    cin >> l >> w >> h >> x >> y >> a;
    double xp = (double)h * cos(a * PI / 180) + x;
    double yp = (double)h * sin(a * PI / 180) + y;
    if(xp > -EPS && xp < w + EPS && yp > -EPS && yp < l + EPS) {
        cout << "YES" << endl;
    } else { 
        cout << "NO" << endl;
    }
    return 0;
}