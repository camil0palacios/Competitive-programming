#include <bits/stdc++.h>
#define endl '\n'
#define fori(i,a,b) for(int i = a; i < b; i++) 
#define ll long long
using namespace std;

const int MXN = 1e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; ll k;
    cin >> n >> k;
    fori(i, 0, n) cin >> a[i];
    sort(a, a + n);
    k--;
    int i, t;
    for(i = 0; i < n; i += t) {
        for(t = 1; a[i] == a[i + t]; t++);
        if(1LL*t*n > k) break;
        k -= 1LL*t*n;
    }
    cout << a[i] << ' ' << a[k/t] << endl;
    return 0;
}