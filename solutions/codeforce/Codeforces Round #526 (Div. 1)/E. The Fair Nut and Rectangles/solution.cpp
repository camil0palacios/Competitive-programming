#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e6 + 5;

struct Line {
    ll m, b;
    Line() {}
    Line(ll m, ll b): m(m), b(b) {}
    ll calc(ll x) { return m * x + b; }
};

int sz = 0;
ll dp[MXN];
Line stk[MXN];
vector< vector<ll> > r;

long double in(Line& a, Line& b) {
    return  ((long double)(b.b - a.b)) / (a.m - b.m);
}

ll query(ll x) {
    static int i = 0;
    while(i + 1 < sz && stk[i].calc(x) < stk[i + 1].calc(x)) i++;
    return stk[i].calc(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll x, y, a;
        cin >> x >> y >> a;
        r.push_back({x, y, a});
    }
    sort(r.begin(), r.end());
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll x = r[i - 1][0], y = r[i - 1][1], a = r[i - 1][2];
        if(i > 1) dp[i] = max(dp[i], query(y));
        Line l = Line(-x, x*y - a + dp[i]);
        while(sz >= 2 && in(stk[sz - 2], l) < in(stk[sz - 1], l)) sz--;
        stk[sz++] = l;
        dp[i] = max(dp[i], x*y - a + query(y));
        dp[i] = max(dp[i], x*y - a);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}