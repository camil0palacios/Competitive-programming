#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;  
int a[MXN];
int sum[MXN*2], mp[MXN*2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(sum, 0, sizeof sum);
        memset(mp, 0, sizeof mp);
        for(int i = 0; i < n / 2; i++) {
            int l = min(a[i], a[n - i - 1]);
            int r = max(a[i], a[n - i - 1]) + k;
            sum[l + 1]++, sum[r + 1]--;
            mp[a[i] + a[n - i - 1]]++;
        }
        int x = 0;
        for(int i = 2; i <= 2*k; i++) {
            sum[i] += sum[i - 1];
        }
        int ans = n;
        for(int i = 2; i <= 2*k; i++) {
            ans = min(ans, (sum[i] - mp[i]) + (n / 2 - sum[i]) * 2);
        }
       cout << ans << endl;
    }
    return 0;
}