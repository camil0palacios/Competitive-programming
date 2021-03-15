#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(all(a));
    sort(all(b));
    int ans = 0, j = 0;
    for(int i = 0; i < n; i++) {
        while(j < m && b[j] < a[i] - k) j++;
        if(j < m && a[i] - k <= b[j] && b[j] <= a[i] + k) {
            ans++;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}