#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
    double r1, r2, r3;
    cin >> r1 >> r2 >> r3;
    double d1 = r1 + r2;
    double d2 = r2 + r3;
    double d3 = r1 + r3;
    double s = (d1 + d2 + d3) / 2.0;
    double At = sqrt(s*(s - d1)*(s - d2)*(s - d3));
    double a1 = acos((d1*d1 + d3*d3 - d2*d2) / (2.0*d1*d3));
    double a2 = acos((d1*d1 + d2*d2 - d3*d3) / (2.0*d1*d2));
    double a3 = acos((d2*d2 + d3*d3 - d1*d1) / (2.0*d2*d3));
    double A = (a1 * r1 * r1) / 2;
    double B = (a2 * r2 * r2) / 2;
    double C = (a3 * r3 * r3) / 2;
    cout << At - A - B - C << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10) << endl;
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol();
    }
    return 0;
}