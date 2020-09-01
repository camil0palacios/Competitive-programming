#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long n, m;
        cin >> n >> m;
        if(n == 1) cout << 0 << endl;
        else if(n == 2) cout << m << endl;
        else cout << m * 2 << endl;
    }
    return 0;
}