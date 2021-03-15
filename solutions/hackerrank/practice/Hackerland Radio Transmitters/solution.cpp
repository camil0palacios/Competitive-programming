#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int x[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    int i = 0, ans = 0;
    while(i < n) {
        ans++;
        int nxt = x[i] + k;
        while(i < n && x[i] <= nxt) i++;
        nxt = x[--i] + k;
        while(i < n && x[i] <= nxt) i++;
    }
    cout << ans << endl;
    return 0;
}