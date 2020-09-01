#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int n, q, a[MXN];

void read(int & x) {
    scanf("%d", &x);
}

void print(int x) {
    printf("%d\n", x);
}

void sol() {
    read(n), read(q);
    for(int i = 0; i < n; i++) {
        read(a[i]);
    }
    sort(a, a + n);
    while(q--) {
        int l, r;
        read(l), read(r);
        l = lower_bound(a, a + n, l) - a;
        r = upper_bound(a, a + n, r) - a;
        print(r - l);
    }
}

int main() {
    int t;
    read(t);
    for(int cs = 1; cs <= t; cs++) {
        printf("Case %d:\n", cs);
        sol();
    }
    return 0;
}