#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mn = 100000;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;

    ll r = c / wr;
    ll b = c / wb;

    ll ans = 0;
    for(int i = 0; i <= min(r, mn); i++) {
        ans = max(ans, i*hr + ((c - i*wr) / wb) * hb);
    }

    for(int i = 0; i <= min(b, mn); i++){
        ans = max(ans, i*hb + ((c - i*wb) / wr) * hr); 

    }
    cout << ans << endl;
    return 0;
}