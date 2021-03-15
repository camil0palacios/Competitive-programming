#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dig[4] = {1, 2, 3, 4};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string x;
        cin >> x;
        int ans = 0;
        for(int i = 1; i < x[0] - '0'; i++) {
            ans += 10;
        }
        for(int i = 0; i < x.size(); i++) {
            ans += dig[i];
        }
        cout << ans << endl;
    }
    return 0; 
}