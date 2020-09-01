#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        cout << (n + 1) * (n + 1) - 1 << endl; 
    }
    return 0;
}