#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[8010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int c[n + 1];
        memset(c, 0, sizeof c);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            c[a[i]]++;
        }
        int s[n + 1];
        memset(s, 0, sizeof s);
        for(int l = 0; l < n; l++) {
            int sum = a[l];
            for(int r = l + 1; r < n; r++) {
                sum += a[r];
                if(sum <= n && c[sum]){
                    s[sum] = c[sum];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            ans += s[i];
        }
        cout << ans << endl;
    }
    return 0;
}