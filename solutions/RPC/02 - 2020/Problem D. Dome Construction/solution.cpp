#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
double x[MXN], y[MXN], z[MXN], r[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    double l = 0, r = 1e9;
    for(int i = 0; i < 1000; i++) {
        double mid = (l + r) / 2;
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            double ra = sqrt(x[j]*x[j] + y[j]*y[j] + z[j]*z[j]);
            cnt += (ra <= mid);
        }
        if(k <= cnt) r = mid;
        else l = mid;
    }
    cout << l << endl;
    return 0;
}