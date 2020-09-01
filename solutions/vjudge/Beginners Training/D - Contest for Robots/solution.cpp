#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], b[n];
    int sa = 0, sb = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sa += a[i];
    }
    int eq[n], it = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(a[i] && !x)eq[it++] = 1;
        sb += x;
    }
    if(sa && sb != n && it) {
        int i = 0, mx = 1;
        while(sa <= sb) {
            sa -= eq[i % it];
            eq[i % it]++;
            sa += eq[i % it];
            mx = max(mx, eq[i % it]);
            i++;
        }
        cout << mx << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}