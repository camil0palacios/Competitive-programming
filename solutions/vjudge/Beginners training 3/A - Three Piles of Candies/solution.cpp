#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        a[1] += a[0];
        if(a[1] > a[2])swap(a[1], a[2]);
        long long x = a[2] - a[1];
        a[1] += x / 2;
        cout << a[1] << endl;
    }
    return 0;
}