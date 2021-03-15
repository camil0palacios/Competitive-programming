#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        long long a = k * (y + 1) - 1;
        long long b = a / (x - 1) + (a % (x - 1) != 0);
        cout << k + b << endl; 
    }
    return 0;
}