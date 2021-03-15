#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int Mxn = 5e5 + 5;
ll a[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll suff[n];
    suff[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }
    map<ll, int> m;
    ll sum = a[0], ans = 0;
    m[2LL*a[0]]++;
    for(int i = 1; i < n - 1; i++) {
        sum += a[i];
        if(m.count(sum) && sum == 2LL*suff[i + 1]) {
            ans += m[sum];
        }
        m[2LL*sum]++;
    }
    cout << ans << endl;
    return 0;
}