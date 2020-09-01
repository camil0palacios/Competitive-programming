#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[110];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, j = 0;
    for(int i = 0; i < n && a[i] <= k; i++, j++){
        ans++;
    }
    for(int i = n - 1; i >= j && a[i] <= k; i--) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}