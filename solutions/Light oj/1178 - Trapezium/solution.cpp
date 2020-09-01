#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a < c) swap(a, c);
    double y = (b*b - d*d + a*a + c*c - 2*a*c) / (2*a - 2*c);
    double x = a - y - c;
    double h = sqrt(d*d - x*x);
    double A = (x * h) / 2.0;
    double B = c * h;
    double C = (y * h) / 2.0;
    cout << A + B + C << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(16);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol(); 
    }
    return 0;
}