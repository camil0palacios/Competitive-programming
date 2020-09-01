#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int x[MXN];

bool check(int lim, int n, int c) {
    int lst = 0, cnt = 1;
    for(int i = 1; i < n; i++) {
        if(x[i] - x[lst] >= lim) {
            cnt++;
            lst = i;
        }
    }
    return cnt >= c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }
        sort(x, x + n);
        int l = 0, r = 1e9 + 5, ans = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(mid, n, c)) ans = mid, l = mid + 1;
            else r = mid - 1; 
        }
        cout << ans << endl;
    } 
    return 0;
}