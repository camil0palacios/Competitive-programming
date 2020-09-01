#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e5 + 5;
ll a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> a[i];       
    }
    sort(a, a + n);
    int ans = 0, l = 0, r = n - 1;
    while(l <= r) {
        if(a[l] + a[r] <= c) l++;
        r--;
        ans++;
    }
    cout << ans << endl;
    return 0;
}