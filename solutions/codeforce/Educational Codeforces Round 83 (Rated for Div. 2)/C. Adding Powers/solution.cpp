#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        long long a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long mxp = 1LL;
        while(mxp < 1e16) {
            mxp *= k;
        }
        bool ok = 1;
        while(mxp) {
            vector<int> p;
            for(int i = 0; i < n; i++) {
                if(a[i] >= mxp) {
                    p.emplace_back(i);
                }
            }
            if(!p.empty()) {
                if(p.size() > 1){
                    ok = 0;
                    break;
                }
                a[p[0]] -= mxp;
            }
            mxp /= k;
        }
        for(int i = 0; i < n; i++) {
            ok &= a[i] == 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}