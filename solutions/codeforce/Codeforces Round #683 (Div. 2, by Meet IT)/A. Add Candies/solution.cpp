#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << n << endl;
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << endl;
    }
    return 0;
}