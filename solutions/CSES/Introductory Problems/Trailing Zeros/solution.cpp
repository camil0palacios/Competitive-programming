#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ll inc = 5, ans = 0;
    while(inc <= n) {
        ans += n / inc;
        inc *= 5;
    }
    cout << ans << endl;
    return 0;
}