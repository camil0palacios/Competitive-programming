#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXK = 1e5 + 5;
int n, k, A, B;
int a[MXK];

int get(int l, int r) {
    return upper_bound(a, a + k, r) - lower_bound(a, a + k, l);
}


ll solve(int l, int r) {
    int x = get(l, r);
    if(x == 0) return A;
    if(l == r) return B * x;
    int m = (l + r) >> 1;
    return min(solve(l, m) + solve(m + 1, r), 1LL * B * (r - l + 1) * x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> A >> B;
    for(int i = 0; i < k; i++) cin >> a[i];
    sort(a, a + k);
    cout << solve(1, 1 << n) << endl;
    return 0;
}