#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // ai + aj = x
    // ai = x - aj
    map<int, int> m;
    bool ok = 0;
    for(int i = 0; i < n; i++) {
        if(m.count(x - a[i])) {
            cout << m[x - a[i]] + 1 << ' ' << i + 1 << endl;
            ok = 1;
            break;
        }
        m[a[i]] = i;
    }
    if(!ok) cout << "IMPOSSIBLE" << endl;
    return 0;
}