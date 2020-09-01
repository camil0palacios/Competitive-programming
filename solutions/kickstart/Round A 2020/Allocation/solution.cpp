#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
    int n, b;
    cin >> n >> b;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n && a[i] <= b; i++) {
        b -= a[i];
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}