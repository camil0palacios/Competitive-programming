#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int n, k;
int a[MXN];

bool check(int lim, bool cur) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!cur){ 
            cnt++, cur ^= 1;
        } else {
            if(a[i] <= lim) {
                cnt++;
                cur ^= 1;
            }
        }
    }
    return cnt >= k;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k; 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 1e9 + 5, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid, 0) || check(mid, 1)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}