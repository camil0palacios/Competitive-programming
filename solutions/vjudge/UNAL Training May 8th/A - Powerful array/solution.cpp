#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2000000;
const int MXA = 1e6 + 5;
const int sq = 450;
int n, t;
int a[MXN], cnt[MXA];

struct Query {
    int l, r, idx;
    Query() {}
    Query(int l, int r, int idx): l(l), r(r), idx(idx) {}
    bool operator<(const Query & q) {
        return make_pair(l / sq, r) < make_pair(q.l / sq, q.r);
    }
};

void add(int idx, ll & res) {
    ll x = cnt[a[idx]];
    res -= x*x*a[idx];
    x = ++cnt[a[idx]];
    res += x*x*a[idx];
}

void remove(int idx, ll & res) {
    ll x = cnt[a[idx]];
    res -= x*x*a[idx];
    x = --cnt[a[idx]];
    res += x*x*a[idx];
}

void mo(vector<Query> & queries, vector<ll> & ans) {
    sort(queries.begin(), queries.end());
    int l = 0, r = -1;
    ll res = 0;
    for(auto & q: queries) {
        while(r < q.r) { r++; add(r, res); }
        while(r > q.r) { remove(r, res); r--; }
        while(l > q.l) { l--; add(l, res); }
        while(l < q.l) { remove(l, res); l++; }
        ans[q.idx] = res;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> t;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<Query> queries;
    for(int i = 0; i < t; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        queries.emplace_back(l, r, i);
    }
    vector<ll> ans(t);
    mo(queries, ans);
    for(auto & res: ans) {
        cout << res << endl;
    }
    return 0;
}