#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct schedule {
    int l, r, i;
    schedule() {}
    schedule(int l, int r, int i): l(l), r(r), i(i) {}
    bool operator<(const schedule & s) const {
        return make_tuple(l, r, i) < make_tuple(s.l, s.r, s.i);
    }
};

const int MXN = 1005;
schedule a[MXN];

void sol() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].i = i;
    }
    sort(a, a + n);
    string ans(n, 'x');
    int cl = 0, cr = 0, ml = 0, mr = 0, ok = 1;
    for(int i = 0; i < n; i++) {
        if(cr <= a[i].l) {
            cl = a[i].l;
            cr = a[i].r;
            ans[a[i].i] = 'C'; 
        }
        else if(mr <= a[i].l) {
            ml = a[i].l;
            mr = a[i].r;
            ans[a[i].i] = 'J';
        }
        else ok = 0;
    }
    cout << (ok ? ans : "IMPOSSIBLE") << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol(); 
    }
    return 0;
}