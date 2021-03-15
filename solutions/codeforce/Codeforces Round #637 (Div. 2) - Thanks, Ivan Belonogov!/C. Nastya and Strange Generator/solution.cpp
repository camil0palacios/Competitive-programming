#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> pos(n);
        for(int i = 0; i < n; i++) 
            pos[--a[i]] = i;
        vector<bool> good(n);
        bool ok = 0;
        for(int i = 0; i < n; i++) {
            if(good[i]) continue;
            int p = pos[i];
            while(p < n) {
                good[p] = 1;
                if(p + 1 == n) break;
                if(good[p + 1]) break;
                if(a[p + 1] == a[p] + 1) {
                    p++;
                    continue;
                }
                ok = 1;
                break;
            }
            if(ok) break;
        }
        cout << (ok ? "No" : "Yes") << endl;
    }
    return 0;
}