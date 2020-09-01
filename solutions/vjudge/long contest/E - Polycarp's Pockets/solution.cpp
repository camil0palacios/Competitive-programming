#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int cnt[110];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    bool ok = 1;
    int ans = 0;
    while(ok) {
        ok = 0;
        for(int i = 0; i < 101; i++) {
            if(cnt[i])cnt[i]--, ok = 1;
        }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}