#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    while(t--) {
        int n, L;
        cin >> n >> L;
        for(int i = 1; i <= n; i++) cin >> a[i];
        a[0] = 0, a[n + 1] = L;
        int p1 = 0, p2 = n + 1;
        double t1 = 0, t2 = 0;
        double v1 = 1, v2 = 1;
        while(p1 + 1 < p2) {
            double x = (a[p1 + 1] - a[p1]) / v1;
            double y = (a[p2] - a[p2 - 1]) / v2;
            if(t1 + x < t2 + y) {
                t1 += x;
                p1++, v1++;
            } else {
                t2 += y;
                p2--, v2++;
            }
        }
        double dist = a[p1 + 1] - a[p1];
        if(t1 < t2) dist -= (t2 - t1) * v1;
        else dist -= (t1 - t2) * v2;
        double t = max(t1, t2) + dist / (v1 + v2);
        cout << t << endl;

        // a[n + 1] = l;
        // double t1[n + 1], t2[n + 1];
        // t1[0] = 0, t2[n + 1] = 0;
        // for(int i = 1; i <= n + 1; i++) t1[i] = t1[i - 1] + 1.0 * (a[i] - a[i - 1]) / i;
        // for(int i = n; i >= 1; i--) t2[i] = t2[i + 1] + 1.0*(a[i + 1] - a[i]) / (n - i + 1);
        // for(int i = 1; i <= n + 1; i++) {
        //     if(t1[i] == t2[i]) {
        //         cout << t1[i] << endl;
        //         break;
        //     }
        //     if(t1[i] > t2[i]) {
        //         double x = t1[i - 1], ans = t2[i], dis = a[i] - a[i - 1];
        //         dis -= (ans - x) * i;
        //         ans += dis / (n + 2);
        //         cout << ans << endl;
        //     }
        // }
        
    }
    return 0;
}