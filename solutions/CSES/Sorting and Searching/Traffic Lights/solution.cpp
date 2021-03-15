#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;

struct cmp {
    bool operator()(const ii & x, const ii & y) {
        return x.sd - x.ft > y.sd - y.ft;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, n;
    cin >> x >> n;
    multiset<ii, cmp> s;
    set<int> pos;
    pos.insert(0);
    pos.insert(x);
    s.insert({0, x});
    for(int i = 0; i < n; i++) {
        int p; 
        cin >> p;
        auto it = pos.lower_bound(p);
        int left = *prev(it), right = *it;
        pos.insert(p);
        auto x = s.find({left, right});
        s.erase(x);
        s.insert({left, p});
        s.insert({p, right});
        ii ans = *s.begin();
        cout << ans.sd - ans.ft << ' ';
    }
    return 0;
}