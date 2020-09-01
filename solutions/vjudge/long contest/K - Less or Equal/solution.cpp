#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    bool ok = 1;
    int ans = (k ? a[k - 1] : a[0] - 1);
    if(!ans) ans = -1;
    if(k && k < n && a[k - 1] == a[k]) ok = 0;
    cout << (ok ? ans : - 1) << endl; 
    return 0;
}