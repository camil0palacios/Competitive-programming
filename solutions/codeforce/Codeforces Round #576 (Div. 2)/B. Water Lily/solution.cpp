#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    double h, l;
    cin >> h >> l;
    double A = (l*l - h*h) / (2*h);
    cout << A << endl;
    return 0;
}