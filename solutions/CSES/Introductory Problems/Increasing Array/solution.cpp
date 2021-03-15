#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i - 1]) {
            ans += (ll)a[i - 1] - a[i];
            a[i] = a[i - 1];
        } 
    }
    cout << ans << endl;
    return 0;
}