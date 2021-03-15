#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        int s = accumulate(a, a + 3, 0);
        cout << min(a[0] + a[1], s / 2) << endl;
    }
    return 0; 
}