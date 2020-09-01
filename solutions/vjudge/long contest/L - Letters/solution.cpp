#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
ll a[MXN];

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    ll ps[n]; ps[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    } 
    while(m--) {
        ll b;
        cin >> b;
        int l = 1, r = n;
        while(r - l > 1) {
            int mid = (l + r) >> 1;
            if(ps[mid] <= b)l = mid;
            else r = mid;
        }
        if(ps[l] < b) l++;
        cout << l << ' ' << b - ps[l - 1] << endl;
    }
    return 0;
}