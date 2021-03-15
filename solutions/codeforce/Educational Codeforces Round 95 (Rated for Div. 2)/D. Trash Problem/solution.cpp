#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// p[0] < p[1] < p[2] < .... < p[n - 1]
// if one pile p[n - 1] - p[0]
// if two piles p[0].....p[i - 1]  p[i]......p[n - 1]
// (p[i - 1] - p[0]) + (p[n - 1] - p[i])
// p[n - 1] - p[0]) - (p[i] - p[i + 1])

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    set<int> s;
    multiset<int> d;
    auto add = [&](int x) {
        auto ret = s.insert(x);
        auto it = ret.first;
        if(it != s.begin() && next(it) != s.end()) {
            d.erase(d.find(*next(it) - *prev(it)));
        }
        if(next(it) != s.end()) {
            d.insert(*next(it) - *it);
        }
        if(it != s.begin()) {
            d.insert(*it - *prev(it));
        }
    };
    auto erase = [&](int x) {
        auto it = s.find(x);
        if(it != s.begin()) {
            d.erase(d.find(*it - *prev(it)));
        }
        if(next(it) != s.end()) {
            d.erase(d.find(*next(it) - *it));
        }
        if(it != s.begin() && next(it) != s.end()) {
            d.insert(*next(it) - *prev(it));
        }
        s.erase(it);
    };
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        add(x);
    }
    for(int i = 0; i <= q; i++) {
        if(d.empty()) {
            cout << 0 << endl;
        } else {
            int max_p = *prev(s.end());
            int min_p = *s.begin();
            int max_d = *prev(d.end());
            cout << max_p - min_p - max_d << endl;
        }
        if(i == q) break;
        int t, x;
        cin >> t >> x;
        if(t == 0) {
            erase(x);
        } else {
            add(x);
        }
    }
    return 0;
}