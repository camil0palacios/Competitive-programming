#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long p, f, cnts, cntw, s, w;
        cin >> p >> f >> cnts >> cntw >> s >> w;
        if(s > w) {
            swap(s, w);
            swap(cnts, cntw);
        }
        long long ans = 0;
        for(int i = 0; i <= min(cnts, p / s); i++) {
            long long w1 = min(cntw, (p - i * s) / w);
            long long s2 = min(cnts - i, f / s);
            long long w2 = min(cntw - w1, (f - s2 * s) / w);
            ans = max(ans, i + w1 + s2 + w2);
        }
        cout << ans << endl;
    }
    return 0;
}