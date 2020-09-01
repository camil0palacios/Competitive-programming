#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k < n / 2) cout << k * 2 + 1;
        else cout << 2*(n - k - 1);
        cout << endl; 
    }
    return 0;
}