#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
using namespace std;

typedef pair<int,int> ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, x;
    cin >> q >> x;
    vector<int> m(x);
    set<ii> s;
    for(int i = 0; i < x; i++) {
        s.insert(mp(m[i], i));
    }
    for(int i = 0; i < q; i++) {
        int y; cin >> y;
        y %= x;
        s.erase(mp(m[y], y));
        ++m[y];
        s.insert(mp(m[y], y));
        cout << s.begin()->first * x + s.begin()->second << endl;
    }
    return 0;
}