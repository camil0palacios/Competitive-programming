#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 998244353;
int p[MAXN], a[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        a[i] = p[i];
    }
    sort(a, a + n);
    set<int> s;
    long long res1 = 0, res2 = 1;
    for(int i = 0; i < k; i++) {
        s.insert(a[n - i - 1]); 
        res1 += a[n - i - 1];
    }
    int i = n - 1;
    for(; i >= 0; i--) {
        if(s.count(p[i]))break;
    }
    int j = i, cnt = 0;
    for(i = i - 1; i >= 0; i--) {
        if(s.count(p[i])) {
            res2 = (res2 * (j - i)) % MOD;
            j = i;
        }
    }
    cout << res1 << ' ' << res2 << endl;
    return 0;
}