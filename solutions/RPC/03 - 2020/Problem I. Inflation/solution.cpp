#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int num = 0, ok = 1;
    double mxx = 0;
    for(int i = 1; i <= n; i++) {
        ok &= a[i] <= i;
        mxx = max(mxx, (i - a[i]) / (1.0 * i));
    }
    if(ok) cout << 1 - mxx << endl;
    else cout << "impossible" << endl;
    return 0;
}