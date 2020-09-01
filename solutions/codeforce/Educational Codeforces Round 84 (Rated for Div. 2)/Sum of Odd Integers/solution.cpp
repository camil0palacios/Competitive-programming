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
        if(n % 2 == k % 2 && k <= n / k) {
            cout << "YES" << endl;    
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}