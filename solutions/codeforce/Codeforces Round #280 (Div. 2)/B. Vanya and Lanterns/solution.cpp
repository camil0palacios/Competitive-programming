#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int n, L;
    cin >> n >> L;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    double l = 0, r = L, ans = 0;
    for(int i = 0; i < 1000; i++) {
        double mid = (l + r) / 2.0;
        int lst = 0;
        bool ok = (a[0] - mid <= 0 && a[n - 1] + mid >= L);
        for(int i = 0; i < n - 1 && ok; i++) {
            if(a[i] + mid >= (double) a[i + 1] - mid) lst = a[i] + mid;
            else ok = 0; 
        }
        if(ok) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}