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
        vector<int> sz(n + 2, 1);
        int mx = 1;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            for(int j = 1; j * j <= i; j++) {
                if(i % j == 0) {
                    if(a[j] < a[i]) sz[i] = max(sz[i], sz[j] + 1);
                    if(i / j != j && a[i / j] < a[i]) 
                        sz[i] = max(sz[i], sz[i / j] + 1);
                }
            }
            mx = max(mx, sz[i]);
        }
        cout << mx << endl;
    }
    return 0;
}