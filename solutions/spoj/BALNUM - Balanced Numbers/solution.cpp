#include <bits/stdc++.h>
#define endl '\n'
#define fori(i, a, b) for(int i = a; i < b; i++)
#define ll long long
using namespace std;

string s;
ll dp[20][2][2][59049];
int pow_3[10];

bool check(int a) {
    int x[10];
    for(int i = 0; i < 10; i++) {
        x[i] = a % 3;
        a /= 3;
    }
    for(int i = 0; i < 10; i++) {
        if(x[i] == 0) continue;
        if(i % 2 == 0 && x[i] == 2) return 0;
        if(i % 2 == 1 && x[i] == 1) return 0;
    }
    return 1;
}

int change(int a, int p) {
    int x[10];
    for(int i = 0; i < 10; i++) {
        x[i] = a % 3;
        a /= 3;
    }
    if(x[p] == 0) x[p] = 1;
    else if(x[p] == 1) x[p] = 2;
    else if(x[p] == 2) x[p] = 1;
    a = 0;
    for(int i = 9; i >= 0; i--) {
        a = a*3 + x[i];
    }
    return a;
}

ll dptop(int idx, bool top, int z, int msk) {
    if(idx == s.size()) return check(msk);
    ll & ans = dp[idx][top][z][msk];
    if(ans != -1) return ans;
    ans = 0;
    int mx = top ? s[idx] - '0' : 9;
    fori(i, 0, mx + 1) {
        ans += dptop(idx + 1, top && i == mx, z || i != 0, (!z && i == 0) ? 0 : change(msk, i));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    pow_3[0] = 1;
    for(int i = 1; i < 10; i++) pow_3[i] = pow_3[i - 1] * 3;
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        s = to_string(x - 1);
        memset(dp, -1, sizeof dp);
        ll ans = dptop(0, 1, 0, 0);
        cin >> x; 
        s = to_string(x);
        memset(dp, -1, sizeof dp);
        cout << dptop(0, 1, 0, 0) - ans << endl;
    }
    return 0;
}