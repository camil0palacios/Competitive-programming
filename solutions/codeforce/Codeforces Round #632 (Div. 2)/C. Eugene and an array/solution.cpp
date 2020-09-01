#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    long long s = 0, ans = 0;
    map<long long, int> m;
    m[0] = 0;
    for(int i = 1, l = 0; i <= n; i++) {
        int x; cin >> x;
        s += x;
        if(m.count(s))
            l = max(l, m[s] + 1);
        ans += i - l;
        m[s] = i;
    }
    cout << ans << endl;
    return 0;
}