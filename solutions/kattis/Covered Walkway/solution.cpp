#include <bits/stdc++.h>
#define endl '\n'
#define ll long long 
using namespace std;

// dp[i] = min(dp[j] + cost(i, j)) 0 <= j < i  cost(i, j) = (x[i] - x[j])^2 + c
// x[i]^2 - 2x[i]x[j] + x[j]^2 + c + dp[j]
// m = -2x[j]
// x = x[i]
// b = dp[j] + x[j]^2

const int MXN = 1000005;

struct CHT {

    struct Line {
        ll m, b;
        Line() {}
        Line(ll m, ll b): m(m), b(b) {}
    };

    int sz, ptr;
    vector<Line> stk;

    CHT(): sz(0), ptr(0) {
        stk.resize(MXN);
    }

    bool check(Line& l1, Line& l2, Line& l3) {
        return (l1.m - l2.m) * (l3.b - l1.b) <= (l1.m - l3.m) * (l2.b - l1.b);
    }

    void add(ll m, ll b) {
        Line l(m, b);
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
        while(ptr + 1 < sz && eval(stk[ptr], x) >= eval(stk[ptr + 1], x)) {
            ptr++;
        }
        return eval(stk[ptr], x);
    }

};

ll x[MXN], dp[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, c;
    cin >> n >> c;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    CHT ch;
    for(int i = 1; i <= n; i++) {
        ch.add(-2LL*x[i], dp[i - 1] + x[i]*x[i]);
        dp[i] = x[i]*x[i] + c + ch.query(x[i]);
    }
    cout << dp[n] << endl;
    return 0;
}