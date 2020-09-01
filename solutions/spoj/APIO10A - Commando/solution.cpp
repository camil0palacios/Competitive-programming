#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1000005;
int a, b, c;
ll x[MXN], s[MXN], dp[MXN];

struct Line {
    ll m, b;
    Line() {}
    Line(ll m, ll b): m(m), b(b) {}
};

struct CHT {

    vector<Line> stk;
    int sz, ptr;

    CHT(): sz(0), ptr(0) {
        stk.resize(MXN);
    }
    // m1 * x + b1 = m2 * x + b2 = x = (b2 - b1)/(m1 - m2);
    // m1 * x + b1 = m3 * x + b3 = x = (b3 - b1)/(m1 - m3);
    bool check(Line l1, Line l2, Line l3) {
        return (l3.b - l1.b) * (l1.m - l2.m) < (l2.b - l1.b) * (l1.m - l3.m); 
    }

    void add(Line l) {
        while(sz >= 2 && check(stk[sz - 2], stk[sz - 1], l)) {
            sz--;
        }
        stk[sz++] = l;
    }

    ll eval(Line& l, int x) {
        return l.m * x + l.b;
    }

    ll query(int x) {
        ptr = min(ptr, sz - 1);
        while(ptr + 1 < sz && eval(stk[ptr], x) < eval(stk[ptr + 1], x)) {
            ptr++;
        }
        return eval(stk[ptr], x);
    }
};

// a(s[i] - s[j]) ^ 2 + b(s[i] - s[j]) + c + dp[j]
// as[i]^2 - 2as[i]s[j] + as[j]^2 + bs[i] - bs[j] + c + dp[j]
// as[i]^2 + bs[i] + c + { -2as[i]s[j] + as[j]^2 - bs[j] + dp[j] }
// m = -2as[j]
// x = s[i]
// c = dp[j] + as[j]^2 - bs[j]


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; 
        ll a, b, c;
        cin >> n >> a >> b >> c;
        for(int i = 1; i <= n; i++) {
            cin >> x[i];
            s[i] = s[i - 1] + x[i];
        }
        CHT ch;
        dp[1] = a*s[1]*s[1] + b*s[1] + c;
        ch.add(Line(-2*a*s[1], dp[1] + a*s[1]*s[1] - b*s[1]));
        for(int i = 2; i <= n; i++) {
            dp[i] = a*s[i]*s[i] + b*s[i] + c; 
            dp[i] = max(dp[i], dp[i] + ch.query(s[i]));
            ch.add(Line(-2*a*s[i], dp[i] + a*s[i]*s[i] - b*s[i]));
        }
        cout << dp[n] << endl;
    }   
    return 0;
}