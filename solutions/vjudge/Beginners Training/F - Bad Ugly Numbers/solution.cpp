#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string ans(n, '3');
        ans[0] = '2';
        cout << (n == 1 ? "-1" : ans) << endl;
    }
    return 0;
}