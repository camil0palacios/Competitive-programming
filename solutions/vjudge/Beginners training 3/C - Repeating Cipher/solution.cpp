#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string t;
    cin >> n >> t;
    string ans;
    int i = 0, plus = 1;
    while(i < n) {
        ans += t[i];
        i += plus;
        plus++;
    }
    cout << ans << endl;
    return 0;
}