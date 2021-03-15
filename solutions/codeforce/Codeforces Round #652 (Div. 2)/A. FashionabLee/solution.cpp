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
        cout << (n % 4 == 0 ? "YES" : "NO") << endl;
    }
    return 0; 
}