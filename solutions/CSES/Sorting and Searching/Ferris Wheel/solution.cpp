#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    int ans = 0;
    while(l <= r) {
        if(a[l] + a[r] <= x) l++;
        r--;
        ans++;
    } 
    cout << ans << endl;
    return 0;
}