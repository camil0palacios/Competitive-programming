#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] -= b[i];
    }
    sort(a, a + n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= 0)continue;
        ans += i - (lower_bound(a, a + n, -a[i] + 1) - a);
    }
    cout << ans << endl;
    return 0;
}