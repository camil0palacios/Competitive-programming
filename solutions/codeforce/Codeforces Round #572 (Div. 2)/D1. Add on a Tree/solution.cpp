#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int deg[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
    }
    if(n == 2) cout << "YES" << endl;
    else if(n == 3) cout << "NO" << endl;
    else {
        bool ok = 1;
        for(int i = 0; i < n; i++) {
            ok &= deg[i] != 2;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}