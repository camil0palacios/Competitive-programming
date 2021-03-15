#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
const int lg = 18;
int a[MXN];
int logg[MXN];
int st[MXN][lg + 1];

void build(int n) {
    logg[1] = 0;
    for(int i = 2; i <= n; i++) {
        logg[i] = logg[i/2] + 1;
    }
    for(int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    for(int j = 1; j <= lg; j++) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rmq(int l, int r) {
    int j = logg[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(n);
    for(int qq = 0; qq < q; qq++) {
        int l, r;
        cin >> l >> r; 
        l--, r--;
        cout << rmq(l, r) << endl;
    }
    return 0;
}