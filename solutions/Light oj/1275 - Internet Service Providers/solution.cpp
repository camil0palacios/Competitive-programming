#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

double equation(double n, double c, double x) {
    if(x*(c - x*n) < 0)return 0;
    return x*(c - x*n);
}

void sol() {
    double n, c;
    cin >> n >> c;
    if(n == 0)cout << 0 << endl;
    else {
        double l = 0, r = 2e9;
        for(int i = 0; i < 2000; i++) {
            double m1 = l + (r - l) / 3.0;
            double m2 = m1 + (r - l) / 3.0;

            if(equation(n, c, m1) < equation(n, c, m2))l = m1;
            else r = m2; 
        }
        double a = floor(l);
        double b = ceil(l);
        if(equation(n, c, a) < equation(n, c, b)) {
            cout << (ll)b << endl;
        } else {
            cout << (ll)a << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol();
    }
    return 0;
}